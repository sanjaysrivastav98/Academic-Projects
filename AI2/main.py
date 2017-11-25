#2015A7PS0102P K S Sanjay Srivastav

from modules import humanMove
from GUI import main_window,close_main_window,drawCoin,getCentre,writeAll
from modules import Successor_function,Terminal_test,printMat,runMinimax,run_alpha_beta
from turtle import *
import turtle

def main():
	i=int(raw_input("Enter an option here: "))
	if i==1:
		main_window()
		close_main_window()
	elif i==2:
		main_window()
		# no_of_nodes=0
		runMinimax()
		close_main_window()
	elif i==3:
		main_window()
		no_of_nodes_ab=0
		run_alpha_beta()
		close_main_window()
	elif i==4:
		main_window()
		writeAll()
		close_main_window()

main()
