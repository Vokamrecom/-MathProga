#pragma once

int levenshtein( // ДИНАМИЧЕСКОЕ ПРОГРАММИРОВАНИЕ
	int lx,           // длина слова x 
	const char x[],   // слово длиной lx
	int ly,           // длина слова y
	const char y[]    // слово y
);


int levenshtein_r( // РЕКУРСИЯ
	int lx,           // длина строки x 
	const char x[],   // строка длиной lx
	int ly,           // длина строки y
	const char y[]    // строка y
);
