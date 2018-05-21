set terminal pngcairo monochrome
set size ratio 0.7
set xlabel 'X'
set ylabel 'U(x,t)'

set output "P_01.png"
unset key
plot "D01_graph1.txt" using 1:2 w l lt 1

reset