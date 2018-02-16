#2015A7PS0102P K S Sanjay Srivastav
from modules import createBayesianNetwork,computeMarkovBlanket,mainGUI
def main():
	n=raw_input('Enter the name of the input file: ')
	cpt=createBayesianNetwork(n)
	mainGUI(cpt)
main()