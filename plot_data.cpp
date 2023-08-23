#include <gnuplot-iostream.h>
#include <boost/iostreams/stream.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

double accum_err(vector<double> des, vector<double> tmp) {
  double accum = 0;
  double err = 0;
  for (size_t i = 0; i < sizeof(des); ++i) {
    err = abs(des[i] - tmp[i]);
    accum += err;
  }
  return round(accum * 100) / 100;
  return accum;
}

int main(int argc, char** argv) {
  // Read data from CSV file
  ifstream inputFile(argv[1]);
  // string mode = argv[2];
  const char *mode = argv[2];
  vector<vector<double>> data;
  string line;
  while (getline(inputFile, line)) {
    vector<double> row;
    istringstream iss(line);
    double value;
    while (iss >> value) {
      row.push_back(value);
      if (iss.peek() == ',')
        iss.ignore();
    }

    data.push_back(row);
  }
  // printf("data : ");
  inputFile.close();
  // Extract columns from data
  vector<double> qd1, q1, qd2, q2, qd3, q3, qd4, q4, qd5, q5, qd6, q6, qd7, q7;
  vector<double> xd, x, yd, y, zd, z, rd, r, pd, p, yad, ya;
  for (const auto& row : data) {
    qd1.push_back(row[0]);
    q1.push_back(row[1]);
    qd2.push_back(row[2]);
    q2.push_back(row[3]);
    qd3.push_back(row[4]);
    q3.push_back(row[5]);
    qd4.push_back(row[6]);
    q4.push_back(row[7]);
    qd5.push_back(row[8]);
    q5.push_back(row[9]);
    qd6.push_back(row[10]);
    q6.push_back(row[11]);
    qd7.push_back(row[12]);
    q7.push_back(row[13]);

    xd.push_back(row[14]);
    x.push_back(row[15]);
    yd.push_back(row[16]);
    y.push_back(row[17]);
    zd.push_back(row[18]);
    z.push_back(row[19]);
    rd.push_back(row[20]);
    r.push_back(row[21]);
    pd.push_back(row[22]);
    p.push_back(row[23]);
    yad.push_back(row[24]);
    ya.push_back(row[25]);
  }

  // Plot first and second columns together
  Gnuplot gp1;
  double max, min, err;
  vector<double> arr, arr0;

  if (strcmp(mode, "joint") == 0) {
    gp1 << "set terminal pngcairo size 1000, 800\n";
    gp1 << "set output 'plot2_joint1-4.png'\n";

    // gp1 << "set terminal svg size 1000, 800\n";
    // gp1 << "set output 'plot_joint1-4.svg'\n";

    // Set multiplot layout 2x2
    gp1 << "set multiplot layout 2,2\n";

    // First subplot
    arr = qd1;
    arr0 = q1;
    err = accum_err(arr, arr0);
    min = *std::min_element(arr.begin(), arr.end()) - 0.01;
    max = *std::max_element(arr.begin(), arr.end()) + 0.01;
    gp1 << "set title 'joint 1 - error: " << fixed << setprecision(2) << err << "'\n";
    gp1 << "set yrange [" << min << ":" << max << "]\n";
    gp1 << "plot '-' with lines title 'desired q', '-' with lines title 'current q'\n";
    gp1.send1d(qd1);
    gp1.send1d(q1);

    // Second subplot
    arr = qd2;
    arr0 = q2;
    err = accum_err(arr, arr0);
    min = *std::min_element(arr.begin(), arr.end()) - 0.01;
    max = *std::max_element(arr.begin(), arr.end()) + 0.01;
    gp1 << "set title 'joint 2 - error: " << err << "'\n";
    gp1 << "set yrange [" << min << ":" << max << "]\n";
    gp1 << "plot '-' with lines title 'desired q', '-' with lines title 'current q'\n";
    gp1.send1d(qd2);
    gp1.send1d(q2);

    // Third subplot
    arr = qd3;
    arr0 = q3;
    err = accum_err(arr, arr0);
    min = *std::min_element(arr.begin(), arr.end()) - 0.01;
    max = *std::max_element(arr.begin(), arr.end()) + 0.01;
    gp1 << "set title 'joint 3 - error: " << err << "'\n";
    gp1 << "set yrange [" << min << ":" << max << "]\n";
    gp1 << "plot '-' with lines title 'desired q', '-' with lines title 'current q'\n";
    gp1.send1d(qd3);
    gp1.send1d(q3);

    // Fourth subplot
    arr = qd4;
    arr0 = q3;
    err = accum_err(arr, arr0);
    min = *std::min_element(arr.begin(), arr.end()) - 0.01;
    max = *std::max_element(arr.begin(), arr.end()) + 0.01;
    gp1 << "set title 'joint 4 - error: " << err << "'\n";
    gp1 << "set yrange [" << min << ":" << max << "]\n";
    gp1 << "plot '-' with lines title 'desired q', '-' with lines title 'current q'\n";
    gp1.send1d(qd4);
    gp1.send1d(q4);

    gp1 << "unset multiplot\n";
    gp1 << "set output\n";

    Gnuplot gp2;

    gp2 << "set terminal pngcairo size 1000, 800\n";

    gp2 << "set output 'plot2_joint5-7.png'\n";
    // Set multiplot layout 2x2
    gp2 << "set multiplot layout 2,2\n";
    // First subplot
    arr = qd5;
    arr0 = q5;
    err = accum_err(arr, arr0);
    min = *std::min_element(arr.begin(), arr.end()) - 0.01;
    max = *std::max_element(arr.begin(), arr.end()) + 0.01;
    gp2 << "set title 'joint 5 - error: " << fixed << setprecision(2) << err << "'\n";
    gp2 << "set yrange [" << min << ":" << max << "]\n";
    gp2 << "plot '-' with lines title 'desired q', '-' with lines title 'current q'\n";
    gp2.send1d(arr);
    gp2.send1d(arr0);

    // Second subplot
    arr = qd6;
    arr0 = q6;
    err = accum_err(arr, arr0);
    min = *std::min_element(arr.begin(), arr.end()) - 0.01;
    max = *std::max_element(arr.begin(), arr.end()) + 0.01;
    gp2 << "set title 'joint 6 - error: " << err << "'\n";
    gp2 << "set yrange [" << min << ":" << max << "]\n";
    gp2 << "plot '-' with lines title 'desired q', '-' with lines title 'current q'\n";
    gp2.send1d(arr);
    gp2.send1d(arr0);

    // Third subplot
    arr = qd7;
    arr0 = q7;
    err = accum_err(arr, arr0);
    min = *std::min_element(arr.begin(), arr.end()) - 0.01;
    max = *std::max_element(arr.begin(), arr.end()) + 0.01;
    gp2 << "set title 'joint 7 - error: " << err << "'\n";
    gp2 << "set yrange [" << min << ":" << max << "]\n";
    gp2 << "plot '-' with lines title 'desired q', '-' with lines title 'current q'\n";
    gp2.send1d(arr);
    gp2.send1d(arr0);
    gp2 << "unset multiplot\n";
    gp2 << "set output\n";
  }

  else if(strcmp(mode, "task")==0){
    gp1 << "set terminal pngcairo size 1600, 1000\n";
    gp1 << "set output 'plot2_endeffector.png'\n";

    gp1 << "set multiplot layout 2,3\n";

    // First subplot
    arr = xd;
    arr0 = x;
    err = accum_err(arr, arr0);
    min = *std::min_element(arr.begin(), arr.end()) - 0.05;
    max = *std::max_element(arr.begin(), arr.end()) + 0.05;
    gp1 << "set title 'x - error: " << fixed << setprecision(2) << err << "'\n";
    gp1 << "set yrange [" << min << ":" << max << "]\n";
    gp1 << "plot '-' with lines title 'desired x', '-' with lines title 'current x'\n";
    gp1.send1d(arr);
    gp1.send1d(arr0);

    // Second subplot
    arr = yd;
    arr0 = y;
    err = accum_err(arr, arr0);
    min = *std::min_element(arr.begin(), arr.end()) - 0.05;
    max = *std::max_element(arr.begin(), arr.end()) + 0.05;
    gp1 << "set title 'y - error: " << err << "'\n";
    gp1 << "set yrange [" << min << ":" << max << "]\n";
    gp1 << "plot '-' with lines title 'desired y', '-' with lines title 'current y'\n";
    gp1.send1d(arr);
    gp1.send1d(arr0);

    // Third subplot
    arr = zd;
    arr0 = z;
    err = accum_err(arr, arr0);
    min = *std::min_element(arr.begin(), arr.end()) - 0.05;
    max = *std::max_element(arr.begin(), arr.end()) + 0.05;
    gp1 << "set title 'z - error: " << err << "'\n";
    gp1 << "set yrange [" << min << ":" << max << "]\n";
    gp1 << "plot '-' with lines title 'desired z', '-' with lines title 'current z'\n";
    gp1.send1d(arr);
    gp1.send1d(arr0);

    // Fourth subplot
    arr = rd;
    arr0 = r;
    err = accum_err(arr, arr0);
    min = *std::min_element(arr.begin(), arr.end()) - 0.1;
    max = *std::max_element(arr.begin(), arr.end()) + 0.1;
    gp1 << "set title 'roll - error: " << err << "'\n";
    gp1 << "set yrange [" << min << ":" << max << "]\n";
    gp1 << "plot '-' with lines title 'desired roll', '-' with lines title 'current roll'\n";
    gp1.send1d(arr);
    gp1.send1d(arr0);

    // Fifth subplot
    arr = pd;
    arr0 = p;
    err = accum_err(arr, arr0);
    min = *std::min_element(arr.begin(), arr.end()) - 0.1;
    max = *std::max_element(arr.begin(), arr.end()) + 0.1;
    gp1 << "set title 'pitch - error: " << err << "'\n";
    gp1 << "set yrange [" << min << ":" << max << "]\n";
    gp1 << "plot '-' with lines title 'desired pitch', '-' with lines title 'current pitch'\n";
    gp1.send1d(arr);
    gp1.send1d(arr0);

    // Sixth subplot
    arr = yad;
    arr0 = ya;
    err = accum_err(arr, arr0);
    min = *std::min_element(arr.begin(), arr.end()) - 0.1;
    max = *std::max_element(arr.begin(), arr.end()) + 0.1;
    gp1 << "set title 'yaw - error: " << err << "'\n";
    gp1 << "set yrange [" << min << ":" << max << "]\n";
    gp1 << "plot '-' with lines title 'desired yaw', '-' with lines title 'current yaw'\n";
    gp1.send1d(arr);
    gp1.send1d(arr0);

    gp1 << "unset multiplot\n";
    gp1 << "set output\n";
  }
  return 0;
}