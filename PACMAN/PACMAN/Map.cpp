#include "Map.h"
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
		fileConfig >> secondLine;
		prev = 0, pos = 0;
		pos = secondLine.find(" ", prev);

	}
	else
	{
		numRows = NUM_ROWS;
		numColumns = NUM_COLUMNS;
		
	};

	InitializeMap();
}

void Map::InitializeMap()
{
	
}




void Map::printMap() {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	// Reposicionem el cursor a l'inici de la consola per repintar sense esborrar (evitant el flickering o pampallugues)
	SetConsoleCursorPosition(console, { 0,0 });

	

	for (int i = -1; i < numRows + 1; i++) {
		for (int j = -1; j < numColumns + 1; j++) {
					if (map[i][j] == 'X')
						SetConsoleTextAttribute(console, 12);	// Els blocs en vermell brillant
						
					else if (map[i][j] == '>')
						SetConsoleTextAttribute(console, 10);	// La plataforma en verd brillant
					std::cout << map[i][j];
			
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
