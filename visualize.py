#file to visualize the output from the cpp AI director text prototype
import csv
import matplotlib.pyplot as plt
import numpy as np



#code for the accepted graph 
'''
firstRow = True
accepted = 0
total = 0
labels = []
values = []
with open('output/gatherBot1000_a.csv','rt')as f:
	data = csv.reader(f)
	for row in data:
		if firstRow:
			accepted = int(row[1])
			total = int(row[2])
			firstRow = False
		labels.append(row[0])
		values.append(int(row[1]))

labels = labels[1:]
values = values[1:]

print(accepted/total)


index = np.arange(len(labels))
plt.bar(index, values)
plt.xlabel('Type distribution', fontsize=10)
plt.ylabel('Frequency', fontsize=10)
plt.xticks(index, labels, fontsize=10, rotation=30)
plt.title('Number of Quest Proposals with X accepted')
plt.show()
'''

#code for 1 of the heatmaps
allData = []
with open('output/gatherBot1000_h.csv','rt')as f:
	data = csv.reader(f)
	for row in data:
		allData.append(row)

#generate heatmap data for the "gather" quests

#auto generate axis labels
questTypes = ["gather", "harvest", "build", "craft", "refine", "attack"]
otherTypes = ["harvest", "build", "craft", "refine", "attack"]
yaxis = []
for type in otherTypes:
	for i in range(0, 6):
		yaxis.append(str(i) + " " + type)

xaxis = ["0 gather", "1 gather", "2 gather", "3 gather", "4 gather", "5 gather"]

#generate the heatmap data from the data
for i in range(len(allData)):
	for j in range(len(allData[0])):

