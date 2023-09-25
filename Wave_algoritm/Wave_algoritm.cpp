#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>

HANDLE hConsole;  //для цвета

int DRP_clone[25][25]{}; // если пути нет


int DRP[25][25] = {
	{0,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{-1,0 - 1,0,-1,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,-1,-1,0,0,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,-1,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};


void print_DRP(int DRP[25][25])
{

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //для цвета
	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			switch (DRP[i][j])
			{
			case 0:
				SetConsoleTextAttribute(hConsole, 2);
				std::cout << std::setw(3) << std::right << (char)46;
				break;
			case -65:
				SetConsoleTextAttribute(hConsole, 1);
				std::cout << std::setw(3) << std::right << (char)65;
				break;
			case -66:
				SetConsoleTextAttribute(hConsole, 1);
				std::cout << std::setw(3) << std::right << (char)66;
				break;
			case -36:
				SetConsoleTextAttribute(hConsole, 8);
				std::cout << std::setw(3) << std::right << (char)36;
				break;
			case -1:
				SetConsoleTextAttribute(hConsole, 4);
				std::cout << std::setw(3) << std::right << (char)37;
				break;
			default:
				SetConsoleTextAttribute(hConsole, 15);
				std::cout << std::setw(3) << std::right << DRP[i][j];
				break;
			}
		}
		std::cout << '\n';
	}
	std::cout << "\n\n\n";
};

void print_In_File(int DRP[25][25])
{
	std::ofstream fout;
	fout.open("out.log", std::ofstream::app);
	if (!fout.is_open())                           //проверка на существование файла
	{
		std::cout << "ERROR NOT FOUND FILE\n";
	}
	else {
		for (int i = 0; i < 25; ++i)
		{
			for (int j = 0; j < 25; ++j)
			{
				switch (DRP[i][j])
				{
				case 0:
					//SetConsoleTextAttribute(hConsole, 2);
					fout << std::setw(3) << std::right << (char)46;
					break;
				case -65:
					//SetConsoleTextAttribute(hConsole, 1);
					fout << std::setw(3) << std::right << (char)65;
					break;
				case -66:
					//SetConsoleTextAttribute(hConsole, 1);
					fout << std::setw(3) << std::right << (char)66;
					break;
				case -1:
					//SetConsoleTextAttribute(hConsole, 4);
					fout << std::setw(3) << std::right << (char)37;
					break;
				default:
					//SetConsoleTextAttribute(hConsole, 15);
					fout << std::setw(3) << std::right << DRP[i][j];
					break;
				}
			}
			fout << "\n";
		}
		fout << "========================================================================\n";
	}
	fout.close();
}

void print_away_path(int DRP[25][25])
{
	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			switch (DRP[i][j])
			{
			case 0:
				SetConsoleTextAttribute(hConsole, 2);
				std::cout << std::setw(3) << std::right << (char)46;
				break;
			case -65:
				SetConsoleTextAttribute(hConsole, 1);
				std::cout << std::setw(3) << std::right << (char)65;
				break;
			case -66:
				SetConsoleTextAttribute(hConsole, 1);
				std::cout << std::setw(3) << std::right << (char)66;
				break;
			case -36:
				SetConsoleTextAttribute(hConsole, 8);
				std::cout << std::setw(3) << std::right << (char)36;
				break;
			case -1:
				SetConsoleTextAttribute(hConsole, 4);
				std::cout << std::setw(3) << std::right << (char)37;
				break;
			default:
				SetConsoleTextAttribute(hConsole, 2);
				std::cout << std::setw(3) << std::right << (char)46;
				break;
			}
		}
		std::cout << '\n';
	}
	std::cout << "\n\n\n";
}

void print_away_path_In_File(int DRP[25][25])
{

	std::ofstream fout;
	fout.open("out.log", std::ofstream::app);
	if (!fout.is_open())                           //проверка на существование файла
	{
		std::cout << "ERROR NOT FOUND FILE\n";
	}
	else {
		for (int i = 0; i < 25; ++i)
		{
			for (int j = 0; j < 25; ++j)
			{
				switch (DRP[i][j])
				{
				case 0:

					fout << std::setw(3) << std::right << (char)46;
					break;
				case -65:

					fout << std::setw(3) << std::right << (char)65;
					break;
				case -66:

					fout << std::setw(3) << std::right << (char)66;
					break;
				case -36:

					fout << std::setw(3) << std::right << (char)36;
					break;
				case -1:
					fout << std::setw(3) << std::right << (char)37;
					break;
				default:
					fout << std::setw(3) << std::right << (char)46;
					break;
				}
			}
			fout << '\n';
		}
		fout << "\n\n\n";
	}
	fout.close();
}

int getValue()
{
	while (true)
	{
		//std::cout << "enter number  from diapazoe 0 - 24 \n";
		int value;
		std::cin >> value;

		if ((std::cin.fail()) || (value > 24) || (value < 0))
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cerr << "error please enter 0 to 24! \n";
		}
		else
			return value;
	}
}

bool equal_DRP(int DRP[25][25], int DRP_clone[25][25])
{
	bool flag{ true };
	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			if (DRP[i][j] != DRP_clone[i][j])
				flag = false;
		}
	}
	return flag;
}

void path_away(int DRP[25][25], int B_x, int B_y, int path, bool flag_console = false, bool flag_file = false, bool flag_both = false)
{
	bool flag = true;
	while (flag) {


		bool flag_loop = true;
		for (int i = 0; flag_loop && i < 25; ++i)
		{
			for (int j = 0; flag_loop && j < 25; ++j)
			{
				//final point
				if (i == B_x && j == B_y)
				{
					if ((i + 1) <= 24 && DRP[i + 1][j] == -65) {
						flag = false;
						flag_loop = false;
						break;
					}
					if (((j + 1) <= 24) && (DRP[i][j + 1] == -65))
					{
						flag = false;
						flag_loop = false;
						break;
					}

					if (((i - 1) >= 0) && (DRP[i - 1][j] == -65))
					{
						flag = false;
						flag_loop = false;
						break;
					}

					if (((j - 1) >= 0) && ((DRP[i][j - 1] == -65)))
					{
						flag = false;
						flag_loop = false;
						break;
					}


					if (((i + 1) <= 24) && DRP[i + 1][j] == path - 1)
					{

						DRP[i + 1][j] = -36;
						B_x = i + 1;
						B_y = j;

						//print_away_path(DRP);														  
						path = path - 1;
						continue;

					}

					if (((j + 1) <= 24) && (DRP[i][j + 1] == path - 1))
					{

						DRP[i][j + 1] = -36;
						B_x = i;
						B_y = j + 1;
						//print_away_path(DRP);														  
						path = path - 1;
						continue;


					}


					if (((i - 1) >= 0) && (DRP[i - 1][j] == path - 1))
					{
						DRP[i - 1][j] = -36;
						B_x = i - 1;
						B_y = j;
						//print_away_path(DRP);
						path = path - 1;
						continue;


					}


					if (((j - 1) >= 0) && ((DRP[i][j - 1] == path - 1)))
					{
						DRP[i][j - 1] = -36;
						B_x = i;
						B_y = j - 1;
						//print_away_path(DRP);
						path = path - 1;
						continue;


					}

				}

			}
		}
	}

	if (flag_console && !flag_file)
		print_away_path(DRP);
	if (flag_file && !flag_console)
		print_away_path_In_File(DRP);
	if (flag_file && flag_console)
	{
		print_away_path_In_File(DRP);
		print_away_path(DRP);
	}

}

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cout << "argument not entered!\n";
	}

	std::string mod_log;
	std::string command;

	if (argc == 2)
	{
		std::cout << "!!1!!!!!!!!!!!!!\n";
		return 0;
	}
	if (argc == 3)
	{
		mod_log = argv[1];
		command = argv[2];

		std::cout << mod_log << '\n';
		std::cout << command << '\n';
	}

	bool flag_console{ 0 };
	bool flag_file{ 0 };
	bool flag_both{ 0 };

	if (mod_log == "--log-mode" && command == "console")
	{
		flag_console = true;
	}
	else
		if (mod_log == "--log-mode" && command == "file")
		{
			flag_file = true;
		}
		else
			if (mod_log == "--log-mode" && command == "both")
			{
				flag_both = true;
				flag_console = true;
				flag_file = true;
			}
			else
				return 0;


	print_DRP(DRP);
	//ввод А и В
	int A_x = 0;
	int A_y = 0;
	int B_x = 5;
	int B_y = 5;

	bool flag_A{ true };
	bool flag_B{ true };
	while (flag_A)
	{
		std::cout << "Point A \n";
		std::cout << "enter x: \n";
		A_x = getValue();
		std::cout << "enter y: \n";
		A_y = getValue();

		if (DRP[A_x][A_y] < 0)
		{
			std::cout << "---border_error----\n";
			continue;
		}

		DRP[A_x][A_y] = -65;
		flag_A = false;
	}
	while (flag_B)
	{
		std::cout << "Point B \n";
		std::cout << "enter x: \n";
		B_x = getValue();
		std::cout << "enter y: \n";
		B_y = getValue();

		if (DRP[B_x][B_y] < 0)
		{
			std::cout << "---border_error----\n";
			continue;
		}

		DRP[B_x][B_y] = -66;
		flag_B = false;
	}


	//если рядом две точки
	if ((A_x + 1 < 25) && DRP[A_x + 1][A_y] == -66 || (A_x - 1 >= 0) && DRP[A_x - 1][A_y] == -66 || (A_y + 1 < 25) && DRP[A_x][A_y + 1] == -66 || (A_y - 1 >= 0) && DRP[A_x][A_y - 1] == -66)
	{
		if (flag_console || flag_both) { print_DRP(DRP); std::cout << "way lenth: 1\n"; }

		if (flag_file || flag_both) {
			print_In_File(DRP);
			std::ofstream fout;
			fout.open("out.log", std::ofstream::app);
			fout << "way lenth: 1\n";
			fout.close();
		}
		//std::cout << "way lenth: 1\n";
		return 0;

	}

	//пускаю волны
	int len_count = 0;
	int path = 0;
	bool flag = true;
	while (flag)
	{

		for (int i = 0; i < 25; ++i)
		{
			for (int j = 0; j < 25; ++j)
			{
				DRP_clone[i][j] = DRP[i][j];
			}
		}

		//путь волны
		for (int i = 0; i < 25; ++i)
		{
			for (int j = 0; j < 25; ++j)
			{
				//start point
				if ((i == A_x && j == A_y && len_count == 0)) {

					if ((DRP[i][j + 1] >= 0) && ((j + 1) <= 24))
					{
						DRP[i][j + 1] = 1;
					}
					if ((DRP[i + 1][j] >= 0) && ((i + 1) <= 24))
					{
						DRP[i + 1][j] = 1;
					}
					if ((DRP[i - 1][j] >= 0) && ((i - 1) >= 0))
					{
						DRP[i - 1][j] = 1;
					}

					if ((DRP[i][j - 1] >= 0) && ((j - 1) >= 0))
					{
						DRP[i][j - 1] = 1;
					}
				}

				//middle points
				if (DRP[i][j] == len_count && len_count != 0)
				{
					if (((i + 1) <= 24) && DRP[i + 1][j] == 0 && DRP[i][j] != -1)
					{
						DRP[i + 1][j] = len_count + 1;
					}
					if (((j + 1) <= 24) && DRP[i][j + 1] == 0 && DRP[i][j] != -1)
					{
						DRP[i][j + 1] = len_count + 1;
					}
					if ((i - 1 >= 0) && DRP[i - 1][j] == 0 && DRP[i][j] != -1)
					{
						DRP[i - 1][j] = len_count + 1;
					}
					if ((j - 1 >= 0) && DRP[i][j - 1] == 0 && DRP[i][j] != -1)
					{
						DRP[i][j - 1] = len_count + 1;
					}
				}

			}
		}

		//дошла ли волна до точки
		for (int i = 0; i < 25; ++i)
		{
			for (int j = 0; j < 25; ++j)
			{
				if (i == B_x && j == B_y)
				{
					if (((i + 1) <= 24) && (DRP[i + 1][j] > 0))
					{
						if (flag_console) {
							print_DRP(DRP);
							SetConsoleTextAttribute(hConsole, 15);
							path = DRP[i + 1][j] + 1;
							std::cout << "way lenth: " << path << '\n';
							//if (!flag_both)

							if (flag_file) {
								for (int i = 0; i < 25; ++i)
								{
									for (int j = 0; j < 25; ++j)
									{
										DRP_clone[i][j] = DRP[i][j];
									}
								}
							}



							path_away(DRP, B_x, B_y, path, flag_console, !flag_file, flag_both);
							//print_away_path(DRP);

						}
						if (flag_file) {

							if (flag_console == false && flag_both == false) {
								for (int i = 0; i < 25; ++i)
								{
									for (int j = 0; j < 25; ++j)
									{
										DRP_clone[i][j] = DRP[i][j];
									}
								}
								flag_console = true;
								flag_both = true;
							}


							print_In_File(DRP_clone);
							std::ofstream fout;
							fout.open("out.log", std::ofstream::app);
							path = DRP_clone[i + 1][j] + 1;
							fout << "way lenth: " << path << '\n';
							fout.close();
							path_away(DRP_clone, B_x, B_y, path, !flag_console, flag_file, !flag_both);
							//print_away_path_In_File(DRP);
						}



						return 0;
					}

					if (((j + 1) <= 24) && (DRP[i][j + 1] > 0))
					{
						if (flag_console) {
							print_DRP(DRP);
							SetConsoleTextAttribute(hConsole, 15);
							path = DRP[i][j + 1] + 1;
							std::cout << "way lenth: " << path << '\n';



							if (flag_file) {
								for (int i = 0; i < 25; ++i)
								{
									for (int j = 0; j < 25; ++j)
									{
										DRP_clone[i][j] = DRP[i][j];
									}
								}
							}

							path_away(DRP, B_x, B_y, path, flag_console, !flag_file, flag_both);
							//print_away_path(DRP);
						}
						if (flag_file) {
							if (flag_console == false && flag_both == false) {
								for (int i = 0; i < 25; ++i)
								{
									for (int j = 0; j < 25; ++j)
									{
										DRP_clone[i][j] = DRP[i][j];
									}
								}
								flag_console = true;
								flag_both = true;
							}
							print_In_File(DRP_clone);
							std::ofstream fout;
							fout.open("out.log", std::ofstream::app);
							path = DRP_clone[i][j + 1] + 1;
							fout << "way lenth: " << DRP_clone[i][j + 1] + 1 << '\n';
							fout.close();
							path_away(DRP_clone, B_x, B_y, path, !flag_console, flag_file, !flag_both);
							//print_away_path_In_File(DRP);
						}


						return 0;
					}

					if (((i - 1) >= 0) && (DRP[i - 1][j] > 0))
					{
						if (flag_console) {

							print_DRP(DRP);
							SetConsoleTextAttribute(hConsole, 15);
							path = DRP[i - 1][j] + 1;
							std::cout << "way lenth: " << DRP[i - 1][j] + 1 << '\n';

							if (flag_file) {
								for (int i = 0; i < 25; ++i)
								{
									for (int j = 0; j < 25; ++j)
									{
										DRP_clone[i][j] = DRP[i][j];
									}
								}

							}

							path_away(DRP, B_x, B_y, path, flag_console, !flag_file, flag_both);
							//print_away_path(DRP);
						}

						if (flag_file)
						{
							if (flag_console == false && flag_both == false) {
								for (int i = 0; i < 25; ++i)
								{
									for (int j = 0; j < 25; ++j)
									{
										DRP_clone[i][j] = DRP[i][j];
									}
								}
								flag_console = true;
								flag_both = true;
							}
							print_In_File(DRP_clone);
							std::ofstream fout;
							fout.open("out.log", std::ofstream::app);
							path = DRP_clone[i - 1][j] + 1;
							fout << "way lenth: " << path << '\n';

							fout.close();
							path_away(DRP_clone, B_x, B_y, path, !flag_console, flag_file, !flag_both);
							//print_away_path_In_File(DRP);
						}


						return 0;

					}

					if (((j - 1) >= 0) && ((DRP[i][j - 1] > 0)))
					{

						if (flag_console) {
							print_DRP(DRP);
							SetConsoleTextAttribute(hConsole, 15);
							path = DRP[i][j - 1] + 1;
							std::cout << "way lenth: " << path << '\n';


							if (flag_file)
							{
								for (int i = 0; i < 25; ++i)
								{
									for (int j = 0; j < 25; ++j)
									{
										DRP_clone[i][j] = DRP[i][j];
									}
								}

							}
							path_away(DRP, B_x, B_y, path, flag_console, !flag_file, flag_both);
							//print_away_path(DRP);
						}
						if (flag_file)
						{
							if (flag_console == false && flag_both == false) {
								for (int i = 0; i < 25; ++i)
								{
									for (int j = 0; j < 25; ++j)
									{
										DRP_clone[i][j] = DRP[i][j];
									}
								}
								flag_console = true;
								flag_both = true;
							}
							print_In_File(DRP_clone);
							std::ofstream fout;
							fout.open("out.log", std::ofstream::app);
							path = DRP_clone[i][j - 1] + 1;
							fout << "way lenth: " << path << '\n';
							fout.close();
							path_away(DRP_clone, B_x, B_y, path, !flag_console, flag_file, !flag_both);
							//print_away_path_In_File(DRP);
						}

						return 0;
					}
				}

			}
		}

		//проверка на окоп вокруг
		if (equal_DRP(DRP, DRP_clone))
		{
			if (len_count == 0)
			{ // если окружен сразу 
				if (flag_console) {
					print_DRP(DRP);
					SetConsoleTextAttribute(hConsole, 15);
					std::cout << "PATH DOES NOT EXIST " << '\n';
					return 0;
				}
				if (flag_file)
				{
					print_In_File(DRP);
					std::ofstream fout;
					fout.open("out.log", std::ofstream::app);
					fout << "PATH DOES NOT EXIST " << '\n';
					fout.close();
					return 0;
				}
			}

			if (flag_console) {
				SetConsoleTextAttribute(hConsole, 15);
				std::cout << "PATH DOES NOT EXIST " << '\n';
			}
			if (flag_file)
			{
				std::ofstream fout;
				fout.open("out.log", std::ofstream::app);
				fout << "PATH DOES NOT EXIST " << '\n';
				fout.close();
			}

			return 0;
		}
		len_count++;
		if (flag_console) { print_DRP(DRP); }
		if (flag_file) { print_In_File(DRP); }


		//return 0;
	}
	return 0;
}