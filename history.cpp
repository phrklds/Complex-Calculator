void saveToFile(double a, char op, double b, double result) {
	ofstream file("history.txt", ios::app);
	file << a << " " << op << " " << b << " = " << result << "\n";
	file.close();
}
