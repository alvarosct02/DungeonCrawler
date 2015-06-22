import cv2
nombre = "pared4"

img = cv2.imread(nombre + ".bmp",1)

colores = []
for i in range(16):
	color = []
	for j in range(3):
		color.append(img[0,i][j])
	colores.append(list(color))

espadas = []
a0 = 2
b0 = 1
size = 10
n = 1 #filas
m = 4 #columnas
for a in range(a0,n*(size+1)+a0,size+1):
	for b in range(b0,m*(size+1)+b0,size+1):
		espada = []
		for i in range(0,size):
			f = []
			for j in range (0,size):
				color = []
				for k in range (3):
					color.append(img[i+a,j+b][k])
				f.append(color)
			espada.append(f)
		espadas.append(espada)

for i in range(len(espadas)):
	for j in range(len(espadas[i])):
		print espadas[i][j]
	print

f = open( nombre + ".txt","w")
f.write(str(m*n)+' '+str(len(espadas[0])) + " " + str(len(espadas[0][0])) + "\n\n")
for i in range(len(espadas)):
	for j in range(len(espadas[i])):
		for k in range(len(espadas[i][j])):
			f.write(str(colores.index(espadas[i][j][k]))+"\t")
		f.write("\n")
	f.write("\n")
f.close()