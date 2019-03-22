#include "Map.h"
char buffer[256];
Map::Map() {
	// Inicialitzem atributs
	std::ifstream fileConfig("config.txt");

	if (fileConfig.is_open()) {
		
		std::string firstLine;
		fileConfig >> firstLine;
		size_t prev = 0, pos = 0;
		pos = firstLine.find(";", prev);
		numColumns = atoi((firstLine.substr(0, pos - prev)).c_str());
		prev = pos + 1;
		pos = firstLine.find(";", prev);
		numRows = atoi((firstLine.substr(prev, pos - prev)).c_str());

		// Obtenim el nombre de linies de blocs
		std::string secondLine;
		/*prev = 0, pos = 0;
		pos = secondLine.find(";", prev);
		buffer[256] = atoi((secondLine.substr(0, pos - prev)).c_str());*/
		while (getline(fileConfig, secondLine)) 
		{
			std::cout <<secondLine << std::endl;
		   
		}
		/*for (int i = 0; i < 256; i++) {
			std::cout << buffer[i] << std::endl;
			
		}*/
		fileConfig.close();
		//pos = secondLine.find(" ", prev);
		/*fileConfig.getline(buffer, 100);
		std::cout << buffer << std::endl;*/
	}
	else
	{
		numRows = NUM_ROWS;
		numColumns = NUM_COLUMNS;
		
	};
	

	//InitializeMap();
}

void Map::InitializeMap()
{
	int i;

	map = new char*[numRows];
	for (i = 0; i < numRows; i++) {
		map[i] = new char[numColumns];
	}


	// Pinto blocs en les primeres lineBlocs linies
	/*for (i = 0; i < numRows; i++) {
		for (int j = 0; j < numColumns; j++) {
			if (buffer[i] == 'X')
			{
				map[i][j] == 'X';
			}
			else if (buffer[i] == '*')
			{
				map[i][j] == '*';
			}
			else if (buffer[i] == ' ')
			{
				map[i][j] == ' ';
			}
			std::cout << map[i][j];
				
		}
	}*/
	
	
}




void Map::printMap() {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	// Reposicionem el cursor a l'inici de la consola per repintar sense esborrar (evitant el flickering o pampallugues)
	SetConsoleCursorPosition(console, { 0,0 });

	

	for (int i = 0; i < numRows ; i++) {
		for (int j = 0; j < numColumns ; j++) {
					/*if (map[i][j] == 'X')
						SetConsoleTextAttribute(console, 12);	// Els blocs en vermell brillant
						
					else if (map[i][j] == '*')
						SetConsoleTextAttribute(console, 10);	// La plataforma en verd brillant
					std::cout << map[i][j];*/
			
		}
		std::cout << std::endl;
	}
}




int Map::getNumRows() {
	return numRows;
}

int Map::getNumColumns() {
	return numColumns;
}
