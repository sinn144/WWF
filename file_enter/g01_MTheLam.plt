set terminal pngcairo monochrome enhanced

set xrange [1900:2015]
set xlabel 'time[y]'
set yrange [29575:32500]
set ylabel 'M / {a^2}'

set output "./file_enter/image/P_01.png"
unset key
plot "./file_enter/data/D10_culc.csv"  using 1:2  w l lt 1

reset

set xrange [1900:2015]
set xlabel 'time[y]'
set yrange [-24:-18]
set ylabel '{/Symbol q}_0 [degree]'

set output "./file_enter/image/P_02.png"
unset key
plot "./file_enter/data/D10_culc.csv" using 1:3 w l lt 1

reset

set xrange [1900:2015]
set xlabel 'time[y]'
set yrange [-146:-135]
set ylabel '{/Symbol l}_0 [degree]'

set output "./file_enter/image/P_03.png"
unset key
plot "./file_enter/data/D10_culc.csv" using 1:4 w l lt 1

reset