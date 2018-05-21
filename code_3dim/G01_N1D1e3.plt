set terminal pngcairo monochrome
set xlabel 'X'
set ylabel 'Y'
set zlabel 'U(x,y,t)'

unset ztics

set xrange [0:1]
set yrange [0:1]

set view 15,40,1,1
# 

set output "P_01.png"
unset key
splot "D01_graph.txt" using 1:2:3 with lines

reset