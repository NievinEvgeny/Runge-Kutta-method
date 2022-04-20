set terminal png
set output "graph.png"

set xrange [0:1]

set yrange [1:3]

set grid

set ylabel "y"

set xlabel "x"

plot "./output.txt" using 1:2 with lines title "Runge-Kutta method"