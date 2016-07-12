import sys
import os
from sys import argv

'''
|Algorithm|
____________________________________________________________________________________________________
----|Read in bwa root
----|Read in igenomics root
----|Generate folder subtree: 
    ----|For each read length, create a read length folder:
        ----|For each read length folder that just gets created, create a sequence error rate folder:
            ----|For each sequence error rate folder that just gets created, create a mutation rate folder:
                ----|For each mutation rate folder that just gets created
                	----|Create the SMF files and store them in this folder
                	----|Create the ACPB files and store them in this folder
                	----|Perform compare_results
                	----|Perform compare_mutations
                	----|Perform generateIGenomicsValidationFile
____________________________________________________________________________________________________
'''

READ_LEN_PARAM = 'Read Length'
SEQ_ERR_RATE_PARAM = 'Sequencing Error Rate'
MUT_RATE_PARAM = 'Mutation Rate'
NECESSARY_KEYS_IN_PARAM = [READ_LEN_PARAM, SEQ_ERR_RATE_PARAM, MUT_RATE_PARAM]

UTILITIES_PATH = './full_validation_utilities/my_scripts/'
ACP_TO_ACPB_PATH = UTILITIES_PATH + 'acp_to_acpb.py'
VCF_TO_SMF_PATH = UTILITIES_PATH + 'vcf_to_smf.py'
MCS_TO_SMF_PATH = UTILITIES_PATH + 'mcs_to_smf.py'
COMPARE_MUTS_PATH = UTILITIES_PATH + 'compare_mutations.py'
COMPARE_RESULTS_PATH = UTILITIES_PATH + 'compare_results.py'
GEN_IG_VALIDATION_FILE_PATH = UTILITIES_PATH + 'generateIGenomicsValidationFile.py'

def parametersDictFromParametersFile(file):
	parameters = {}
	for line in file.readlines():
		line = line.strip('\n')
		components = line.split('\t')
		parameters[components[0]] = []
		for i in range(1, len(components)):
			parameters[components[0]].append(float(components[i]))
	return parameters

def stdPrint(txt):
	sys.stdout.write(txt + '\n')

def printDivider():
	stdPrint('____________________________________________________________________________________________________')

def createDirectoryAtPath(path):
    try:
        os.makedirs(path)
        stdPrint('	Create Directory At Path: Dir created - ' + path)
    except:
    	stdPrint('	Create Directory At Path: Already exists - ' + path)

def performComparison(currLeafPath, bwaLeafPath, igLeafPath):
	#Convert iGenomics data file to ACPB
	os.system('python ' + ACP_TO_ACPB_PATH + ' ' + igLeafPath + 'reads.acp ' + currLeafPath + 'reads.ig')

	#Copy BWA reads file to currLeafPath
	os.system('cp ' + bwaLeafPath + 'reads.fq ' + currLeafPath + 'reads.bwa.fq')

	#Convert iGenomics muts file to SMF
	os.system('python ' + MCS_TO_SMF_PATH + ' ' + igLeafPath + 'reads.mutations.mcs ' + currLeafPath + 'mutations.ig')

	#Convert BWA muts file to SMF
	os.system('python ' + VCF_TO_SMF_PATH + ' ' + bwaLeafPath + 'reads.mutations.vcf ' + currLeafPath + 'mutations.bwa')

	#Perform compare_results
	os.system('python ' + COMPARE_RESULTS_PATH + ' ' + currLeafPath + 'reads.bwa.fq ' + currLeafPath + 'reads.ig.acpb > ' + currLeafPath + 'results.out')
	
	#Perform compare_mutations
	os.system('python ' + COMPARE_MUTS_PATH + ' ' + currLeafPath + 'mutations.bwa.smf ' + currLeafPath + 'mutations.ig.smf > ' + currLeafPath + 'mutations.out')

	#Perform generateIGenomicsValidationFile
	os.system('python ' + GEN_IG_VALIDATION_FILE_PATH + ' ' + currLeafPath + 'results.out ' + currLeafPath + 'mutations.out > ' + currLeafPath + 'validation.fin')

def createComparisonTree(bwaPath, igPath, comparisonPath, parameters):
	for readLength in parameters[READ_LEN_PARAM]:
		readLength = int(readLength)

		#Create read length folder if one is not there
		readLenPath = comparisonPath + 'read_len' + str(int(readLength)) + 'bp/'

		readLenBWAPath = bwaPath + 'read_len' + str(int(readLength)) + 'bp/'
		readLenIGPath = igPath + 'read_len' + str(int(readLength)) + 'bp/'

		createDirectoryAtPath(readLenPath)
		for seqErrorRate in parameters[SEQ_ERR_RATE_PARAM]:
			#Create seq error rate folder within the read length folder if one is not there
			seqErrorPath = readLenPath + 'seq_error_rate' + str(seqErrorRate) + '/'
			seqErrorBWAPath = readLenBWAPath + 'seq_error_rate' + str(seqErrorRate) + '/'
			seqErrorIGPath = readLenIGPath +'seq_error_rate' + str(seqErrorRate) + '/'
			createDirectoryAtPath(seqErrorPath)
			for mutRate in parameters[MUT_RATE_PARAM]:
				#Create mut error rate folder within the seq error rate folder if one is not there
				mutRatePath = seqErrorPath + 'mut_rate' + str(mutRate) + '/'
				mutRateBWAPath = seqErrorBWAPath + 'mut_rate' + str(mutRate) + '/'
				mutRateIGPath = seqErrorIGPath + 'mut_rate' + str(mutRate) + '/'
				createDirectoryAtPath(mutRatePath)
				performComparison(mutRatePath, mutRateBWAPath, mutRateIGPath)

def main():
	os.system('clear')
	stdPrint('Auto Comparison: Comparison Started')
	printDivider()

	bwaPath = argv[1]
	igPath = argv[2]
	simParams = argv[3]

	comparisonPath = 'comparison/'
	createDirectoryAtPath(comparisonPath)
	
	paramsFile = open(simParams, 'r')
	paramsDict = parametersDictFromParametersFile(paramsFile)
	paramsFile.close()

	createComparisonTree(bwaPath, igPath, comparisonPath, paramsDict)


if __name__ == "__main__":
	main()