set terminal png
set output "leplot.png"

set title "Evolution of u_n and u_ref over Time"
set xlabel "Time"
set ylabel "Variable Value"

plot 'Variable_u_n_0.data' with lines title 'Initial Condition', \
     'Variable_u_n_20.data' with lines title 'u_n at Final Time', \
     'Variable_u_ref_20.data' with lines title 'u_ref at Final Time'

