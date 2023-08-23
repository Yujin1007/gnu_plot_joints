# gnu_plot_joints
plot each joint angle to compare with desired joint angles

desired .csv contents should include desired q angle and q angle 
in qd1,q1,qd2,q2,qd3,q3,qd4,q4,qd5,q5,qd6,q6,qd7,q7 order. 


build : 
g++ -std=c++11 -o plot_data plot_data.cpp -lboost_iostreams -lboost_system

execute :
./plot_data "nameOfCSV".csv "task or joint"
