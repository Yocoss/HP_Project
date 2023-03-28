#mis a jour avec stockage du job a la fin du script
import os
import shutil

#path to the storage folder to get Abaqus work files 
output_folder = 'C:/Users/Yohann/Documents/Abaqus/Abaqus_1stanalysis/files/job1.jnl'
#define the way to access the existing youngmodulus value
input_file = 'C:/Users/Yohann/Documents/Abaqus/Abaqus_1stanalysis/files/load.inp'
#old newt value
old_value = 1000
#new one
new_value = 1500

#read the input file
with open(input_file, 'r') as f:
    input_data = f.read()

#go through a list of newt values to perform multiple simulations (here 3)
young_modulus_values = [2000, 2500, 3000]

for i, young_modulus in enumerate(young_modulus_values):
    #create a copy of the input file
    modified_input_file = os.path.join(output_folder, f'modified_input1_file_{i}.inp')
    shutil.copy(input_file, modified_input_file)

    #change the old value by the new one
    with open(modified_input_file, 'r') as f:
        input_data = f.read()
    input_data = input_data.replace(str(old_value), str(young_modulus))
    with open(modified_input_file, 'w') as f:
        f.write(input_data)

    #start the abaqus job
    job_file = os.path.join(output_folder, f'job1_file_{i}.jnl')
    os.system(f'abaqus script={job1_file} noGUI=abaqus_commands.py')

#move all the work files in the storage folder
for i in range(len(young_modulus_values)):
    job_file = os.path.join(output_folder, f'job1_file_{i}.jnl')
    shutil.move(job1_file, output_folder)

