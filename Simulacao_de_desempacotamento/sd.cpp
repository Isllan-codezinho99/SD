// SIMULADOR DE DESEMPACOTAMENTO
// Nada nesse codigo realmente funciona, apenas testes que eu mesmo fiz
// Como sempre, aprendi algo novo c++, ja quero criar algo novo
// Dessa vez, aprendi threads
// Auto: Isllan
// Warning: Talvez meu codigo nunca deve esta igual a de um dev de verdade, entao nao me julgue
// Codigo de CONTAR até 5 segundos foi gerado por IA

#include <iostream>
#include <filesystem>
#include <thread>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>

std::string texto_iso = "LINUX OPEN. LINUX COMMAND. LINUX NOTE. LINUX BOOT";
bool c, d;
namespace fs = std::filesystem;

// A funcao de instalacao que na real vai criar o arquivo imaginario chamado de .iso
void criar_intalar() {
	std::ofstream linux_12_GB("C:\\Users\\Isllan Juan\\Downloads\linux.iso"); // Sim, eu sei que errei o .iso, mas é apenas uma simulação

	std::this_thread::sleep_for(std::chrono::seconds(5));
	if (linux_12_GB.is_open() == false) {
		std::cout << "Erro: Arquivo corrompido ou com acesso negado\n";
		return; // Para a função aqui
	}

	linux_12_GB << texto_iso;
	linux_12_GB.close();
	c = true;
}

// A funcao de desempactomento que vai pegar esse linux_12_GB.iso e vai apaga-lo e vai criar em pastas os diretorios, tipo um desempacodador mesmo
void desempacotar() {
	
	try {
		// Remover o linux_12_GB.iso
		fs::remove("C:\\Users\\Isllan Juan\\Downloads\\linux.iso");
		std::this_thread::sleep_for(std::chrono::seconds(5));
		// Criar diretorios
		fs::create_directory("C:\\Users\\Isllan Juan\\Documents\\Linux");
		fs::create_directory("C:\\Users\\Isllan Juan\\Documents\\Linux\\boot");
		fs::create_directory("C:\\Users\\Isllan Juan\\Documents\\Linux\\open");
		fs::create_directory("C:\\Users\\Isllan Juan\\Documents\\Linux\\command");
		fs::create_directory("C:\\Users\\Isllan Juan\\Documents\\Linux\\note");
		d = true;
	}
	catch (const fs::filesystem_error& e) {
		std::cout << e.what() << "\n";
	}
}

// Ponto de partida
int main() {
	// Aqui inicamos as thread
	std::thread processo_instalar(criar_intalar);
	std::thread processo_desempacotar(desempacotar);

	std::cout << "Ola, estamos fazendo a instalacao... espere....\n";
	processo_instalar.join();
	if (c == true) {
		std::cout << "Sistema instalado com sucesso\n";
	}
	std::cout << "Estamos fazendo o desempacotamento, por favor,nao desligue o computador....\n";
	processo_desempacotar.join();
	if (d == true) {
		std::cout << "Sistema instalado no seu computador. Use do jeito que bem imaginar.\n";
	}

	return 0;
}