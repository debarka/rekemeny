# rekemeny
1. The Format of the input is provided in "input.txt" (which is actually the input for hsa-miR-15a as a demo in this Supplementary Material).

2. Relevant information about the input lists is to be provided in "variable.txt". This file is also to be used in case of parameter-tuning.

3. Compile the program in Linux Terminal as : 
	       
		   gcc optimizer.c -lm

4. The Final Fused List can be obtained at the end of the file "results.txt". The rest data in it is the Simulated Annealing Data with the 
   first numeric column corresponding to Kendall's Tau Diatance, second to Shannon Entropy and the third is the Objective Function of the 
   Modified KOA i.e, Kendall's Tau Distance/Shannon Entropy .

# reference
Sengupta, Debarka, Aroonalok Pyne, Ujjwal Maulik, and Sanghamitra Bandyopadhyay. "Reformulated Kemeny optimal aggregation with application in consensus ranking of microrna targets." IEEE/ACM Transactions on Computational Biology and Bioinformatics 10, no. 3 (2013): 742-751.
