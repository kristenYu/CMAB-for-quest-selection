#file to visualize the output from the cpp AI director text prototype
import csv
import matplotlib.pyplot as plt
import numpy as np

#code for the accepted graph 
def generateAcceptedGraph(aidir, filename, botName):
	firstRow = True
	accepted = 0
	total = 0
	labels = []
	values = []
	with open(f'output/{aidir}/{filename}','rt')as f:
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

	print(aidir + " " + filename + ": " + str(accepted/total))


	index = np.arange(len(labels))
	plt.bar(index, values)
	plt.xlabel('Type distribution', fontsize=12)
	plt.ylabel('Frequency', fontsize=12)
	plt.xticks(index, labels, fontsize=9)
	plt.title('Number of Quest Proposals with X accepted')
	plt.savefig(f'graphs/{aidir}/{botName}/accepted_{filename[:-4]}')
	plt.close()

#code for batch heatmaps
def generateBatchHeatmaps(aidir, filename, botName):
	questTypes = ["gather", "harvest", "build", "craft", "refine", "attack"]
	QUESTNUM = 6;

	for type1 in questTypes:
		for type2 in questTypes:
			xaxis = []
			yaxis = []
			for i in range(QUESTNUM):
				xaxis.append(f'{i} {type1}')
				yaxis.append(f'{i} {type2}')

			heatmap = []
			for i in range(QUESTNUM):
				heatmap.append([0, 0, 0, 0, 0, 0])

			with open(f'output/{aidir}/{filename}','rt')as f:
				data = csv.reader(f)
				for row in data:
					r = int(row[0][questTypes.index(type1)])
					c = int(row[0][questTypes.index(type2)])
					heatmap[r][c] += int(row[1])

			m = np.array(heatmap)
			fig, ax = plt.subplots()
			heatmap = np.rot90(m, k=1)
			yaxis = np.flip(yaxis)
			im = ax.imshow(heatmap, cmap = 'Blues')
			cb = fig.colorbar(im)
			# We want to show all ticks...
			ax.set_xticks(np.arange(len(xaxis)))
			ax.set_yticks(np.arange(len(yaxis)))
			# ... and label them with the respective list entries
			ax.set_xticklabels(xaxis)
			ax.set_yticklabels(yaxis)



			# Rotate the tick labels and set their alignment.
			plt.setp(ax.get_xticklabels(), ha="right", rotation_mode="anchor")

			# Loop over data dimensions and create text annotations.
			for i in range(len(yaxis)):
			    for j in range(len(xaxis)):
			        text = ax.text(j, i, heatmap[i][j], ha="center", va="center", color="w")

			ax.set_title(f"Correlation between {type1} and {type2} quests")
			fig.tight_layout()
			#plt.show()
			plt.savefig(f"graphs/{aidir}/{botName}/heatmaps/{type1}{type2}.png")
			plt.close()


#calculate the variety of the quests
def generateVarietyGraph(aidir, filename, botName):
	variety = [0, 0, 0, 0, 0] #0 is considered to be a variety of 1
	with open(f'output/{aidir}/{filename}','rt')as f:
		data = csv.reader(f)
		for row in data:
			v = 0
			for char in row[0]:
				if char != "0":
					v += 1
			variety[v-1] += int(row[1])

	labels = ["1", "2", "3", "4", "5"]

	index = np.arange(len(labels))
	plt.bar(index, variety)
	plt.xlabel('Variety of the Quest Proposal', fontsize=10)
	plt.ylabel('Frequency', fontsize=10)
	plt.xticks(index, labels, fontsize=10)
	plt.title('Number of Quest Proposals with Variety of X')
	plt.savefig(f'graphs/{aidir}/{botName}/variety_{filename[:-4]}.png')
	plt.close()


#TODO: turn the state space map in to a heatmap
def generateStateSpaceMap(aidir, filename, botName):
	from matplotlib.pyplot import figure
	#figure(num=None, figsize=(40, 8), dpi=80, facecolor='w', edgecolor='k')

	xQuests = ["gather", "harvest", "build"]
	yQuests = ["craft", "refine", "attack"]

	xaxis = []
	yaxis = []
	for i in range(2):
		for j in range(2):
			for k in range(2):
				xaxis.append(f'{i}{j}{k}')
				yaxis.append(f'{i}{j}{k}')


	xdata = []
	ydata = []
	with open(f'output/{aidir}/{filename}','rt')as f:
		data = csv.reader(f)
		for row in data:
			generate = ""
			for bit in row[0]:
				if int(bit) != 0:
					generate += "1"
				else:
					generate += "0"
			xdata.append(xaxis.index(generate[:3]))
			ydata.append(yaxis.index(generate[3:]))


	index = np.arange(len(xaxis))
	plt.plot(xdata, ydata, "o")
	plt.margins(x=0.05, y=0.05)
	plt.xticks(index, xaxis, fontsize=8)
	plt.xlabel("Occurance of gather, harvest, build")
	plt.yticks(index, yaxis, fontsize=8)
	plt.ylabel("Occurance of craft, refine, attack")
	plt.title("Range of Quest Proposals Generated")
	plt.savefig(f'graphs/{aidir}/{botName}/range_{filename[:-4]}.png')
	plt.close()




directors = ['random', 'mc1', 'mc2']
bots = ['randomBot', 'gatherBot', 'attackBot']

#d = 'cba'
d = 'random'
for b in bots:
	generateStateSpaceMap(d, f'{b}10000_h.csv', b)
	generateAcceptedGraph(d, f'{b}10000_a.csv', b)
	generateVarietyGraph(d, f'{b}10000_h.csv', b)
	generateBatchHeatmaps(d, f'{b}10000_h.csv', b)
'''

for d in directors:
	for b in bots:
		generateStateSpaceMap(d, f'{b}10000_h.csv', b)
		generateAcceptedGraph(d, f'{b}10000_a.csv', b)
		generateVarietyGraph(d, f'{b}10000_h.csv', b)
		generateBatchHeatmaps(d, f'{b}10000_h.csv', b)
'''