#include <stdio.h> // Biblioteca padrão de entrada e saída 

#include <stdlib.h> // Biblioteca para funções de sistema como system() 

#include <string.h> // Biblioteca para manipulação de strings 

 

#define MAX_PETS 3 // Define o número máximo de pets por tutor 

#define MAX_TUTORES 10 // Define o número máximo de tutores 

 

// Estrutura que representa um pet 

typedef struct { 

  int id; // Identificador único do pet 

  char nome[50]; // Nome do pet 

} Pet; 

 

// Estrutura que representa um tutor 

typedef struct { 

  int id; // Identificador único do tutor 

  char cpf[15]; // CPF do tutor 

  char nome_completo[50]; // Nome do tutor 

  Pet animais[MAX_PETS]; // Lista de pets do tutor 

  int totalAnimais; // Número de pets cadastrados para o tutor 

} Tutor; 

 

// Limpa a tela do terminal 

void limparTela() { 

  #ifdef _WIN32 

    system("cls"); // Windows 

  #else 

    system("clear"); // Linux/Mac 

  #endif 

} 

 

// Espera o usuário pressionar uma tecla 

void aguardarTecla() { 

  printf("\nPressione qualquer tecla para voltar ao menu..."); 

  getchar(); 

} 

 

// Limpa o buffer do teclado para evitar problemas com o scanf/fgets 

void limparBuffer() { 

  int ch; 

  while ((ch = getchar()) != '\n' && ch != EOF); 

} 

 

// Mostra o menu principal na tela 

void exibirMenu() { 

  printf("*****Gestão de Pets*****\n\n"); 

  printf("1 - Listar tutores cadastrados\n"); 

  printf("2 - Cadastrar novo tutor\n"); 

  printf("3 - Atualizar tutor existente\n"); 

  printf("4 - Excluir tutor\n"); 

  printf("5 - Listar pets cadastrados\n"); 

  printf("6 - Cadastrar novo pet\n"); 

  printf("7 - Atualizar pet\n"); 

  printf("8 - Excluir pet\n"); 

  printf("0 - Sair\n\n"); 

  printf("Escolha uma opção: "); 

} 

 

// Lista os tutores 

void listarTutores(Tutor donos[], int totalDonos) { 

  if (totalDonos == 0) { 

    printf("Nenhum tutor cadastrado ainda.\n"); 

  } else { 

    for (int i = 0; i < totalDonos; i++) { 

      printf("CPF: %s\nNome: %s\nPets: %d\n-----------\n", donos[i].cpf, donos[i].nome_completo, donos[i].totalAnimais); 

    } 

  } 

  aguardarTecla(); 

} 

 

// Cadastra um novo tutor 

void cadastrarTutor(Tutor donos[MAX_TUTORES], int *qtdDonos) { 

  if (*qtdDonos >= MAX_TUTORES) { 

    printf("Limite de tutores atingido.\n"); 

    return; 

  } 

 

  char documento[15]; 

  printf("Informe o CPF do tutor: "); 

  fgets(documento, sizeof(documento), stdin); 

  documento[strcspn(documento, "\n")] = '\0'; 

 

  for (int i = 0; i < *qtdDonos; i++) { 

    if (strcmp(donos[i].cpf, documento) == 0) { 

      printf("Esse CPF já está cadastrado.\n"); 

      aguardarTecla(); 

      return; 

    } 

  } 

 

  Tutor novoTutor; 

  novoTutor.id = *qtdDonos + 1; 

  strcpy(novoTutor.cpf, documento); 

 

  limparBuffer(); 

  printf("Digite o nome completo do tutor: "); 

  fgets(novoTutor.nome_completo, sizeof(novoTutor.nome_completo), stdin); 

  novoTutor.nome_completo[strcspn(novoTutor.nome_completo, "\n")] = '\0'; 

  novoTutor.totalAnimais = 0; 

 

  donos[*qtdDonos] = novoTutor; 

  (*qtdDonos)++; 

 

  printf("Tutor cadastrado com sucesso!\n"); 

  aguardarTecla(); 

} 

 

// Atualiza dados de um tutor 

void atualizarTutor(Tutor donos[MAX_TUTORES], int *qtdDonos) { 

  if (*qtdDonos == 0) { 

    printf("Nenhum tutor cadastrado.\n"); 

    aguardarTecla(); 

    return; 

  } 

 

  char nomeBusca[50]; 

  printf("Digite o nome do tutor que deseja atualizar: "); 

  fgets(nomeBusca, sizeof(nomeBusca), stdin); 

  nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; 

 

  for (int i = 0; i < *qtdDonos; i++) { 

    if (strcmp(donos[i].nome_completo, nomeBusca) == 0) { 

      printf("Novo nome: "); 

      fgets(donos[i].nome_completo, sizeof(donos[i].nome_completo), stdin); 

      donos[i].nome_completo[strcspn(donos[i].nome_completo, "\n")] = '\0'; 

 

      printf("Novo CPF: "); 

      fgets(donos[i].cpf, sizeof(donos[i].cpf), stdin); 

      donos[i].cpf[strcspn(donos[i].cpf, "\n")] = '\0'; 

 

      printf("Atualização realizada com sucesso!\n"); 

      aguardarTecla(); 

      return; 

    } 

  } 

 

  printf("Tutor não encontrado.\n"); 

  aguardarTecla(); 

} 

 

// Exclui um tutor 

void excluirTutor(Tutor donos[MAX_TUTORES], int *qtdDonos) { 

  if (*qtdDonos == 0) { 

    printf("Nenhum tutor cadastrado.\n"); 

    aguardarTecla(); 

    return; 

  } 

 

  char nomeExcluir[50]; 

  printf("Digite o nome do tutor a ser removido: "); 

  limparBuffer(); 

  fgets(nomeExcluir, sizeof(nomeExcluir), stdin); 

  nomeExcluir[strcspn(nomeExcluir, "\n")] = '\0'; 

 

  for (int i = 0; i < *qtdDonos; i++) { 

    if (strcasecmp(donos[i].nome_completo, nomeExcluir) == 0) { 

      for (int j = i; j < *qtdDonos - 1; j++) { 

        donos[j] = donos[j + 1]; 

      } 

      (*qtdDonos)--; 

      printf("Tutor excluído com sucesso!\n"); 

      aguardarTecla(); 

      return; 

    } 

  } 

 

  printf("Tutor não encontrado.\n"); 

  aguardarTecla(); 

} 

 

// Lista todos os pets 

void listarPets(Tutor donos[MAX_TUTORES], int qtdDonos) { 

  int temPets = 0; // Inicializa a variável de controle 

  for (int i = 0; i < qtdDonos; i++) { 

    if (donos[i].totalAnimais > 0) { // Verifica se o tutor tem pets 

      for (int j = 0; j < donos[i].totalAnimais; j++) { 

        printf("Pet: %s\nTutor: %s\nCPF: %s\n-----------\n", donos[i].animais[j].nome, donos[i].nome_completo, donos[i].cpf); 

        temPets = 1; // Se encontrar pets, marca a variável como verdadeira 

      } 

    } 

  } 

  if (!temPets) { 

    printf("Nenhum pet cadastrado.\n"); 

  } 

  aguardarTecla(); 

} 

 

// Cadastra um novo pet para um tutor 

void cadastrarPet(Tutor donos[MAX_TUTORES], int qtdDonos) { 

  char cpfBusca[15]; 

  printf("Informe o CPF do tutor: "); 

  limparBuffer(); 

  fgets(cpfBusca, sizeof(cpfBusca), stdin); 

  cpfBusca[strcspn(cpfBusca, "\n")] = '\0'; // Remove o caractere '\n' de fgets 

 

  for (int i = 0; i < qtdDonos; i++) { 

    if (strcmp(donos[i].cpf, cpfBusca) == 0) { 

      if (donos[i].totalAnimais >= MAX_PETS) { 

        printf("Esse tutor já tem o máximo de pets permitidos.\n"); 

        aguardarTecla(); 

        return; 

      } 

 

      char nome_pet[50]; 

      printf("Nome do pet: "); 

      fgets(nome_pet, sizeof(nome_pet), stdin); 

      nome_pet[strcspn(nome_pet, "\n")] = '\0'; // Remove o caractere '\n' de fgets 

 

      for (int j = 0; j < donos[i].totalAnimais; j++) { 

        if (strcmp(donos[i].animais[j].nome, nome_pet) == 0) { 

          printf("Esse pet já foi cadastrado.\n"); 

          aguardarTecla(); 

          return; 

        } 

      } 

 

      Pet novo; 

      novo.id = donos[i].totalAnimais + 1; // Incrementa o ID corretamente 

      strcpy(novo.nome, nome_pet); 

      donos[i].animais[donos[i].totalAnimais++] = novo; // Adiciona o pet e incrementa o totalAnimais 

 

      printf("Pet cadastrado com sucesso!\n"); 

      aguardarTecla(); 

      return; 

    } 

  } 

 

  printf("Tutor não encontrado.\n"); 

  aguardarTecla(); 

} 

 

// Atualiza dados de um pet 

void atualizarPet(Tutor donos[MAX_TUTORES], int qtdDonos) { 

  char cpfBusca[15], nomePet[50]; 

  printf("Informe o CPF do tutor do pet: "); 

  limparBuffer(); 

  fgets(cpfBusca, sizeof(cpfBusca), stdin); 

  cpfBusca[strcspn(cpfBusca, "\n")] = '\0'; 

 

  for (int i = 0; i < qtdDonos; i++) { 

    if (strcmp(donos[i].cpf, cpfBusca) == 0) { 

      printf("Nome do pet a ser atualizado: "); 

      fgets(nomePet, sizeof(nomePet), stdin); 

      nomePet[strcspn(nomePet, "\n")] = '\0'; 

 

      for (int j = 0; j < donos[i].totalAnimais; j++) { 

        if (strcmp(donos[i].animais[j].nome, nomePet) == 0) { 

          printf("Novo nome para o pet: "); 

          fgets(donos[i].animais[j].nome, sizeof(donos[i].animais[j].nome), stdin); 

          donos[i].animais[j].nome[strcspn(donos[i].animais[j].nome, "\n")] = '\0'; 

 

          printf("Pet atualizado com sucesso!\n"); 

          aguardarTecla(); 

          return; 

        } 

      } 

      printf("Pet não encontrado.\n"); 

      aguardarTecla(); 

      return; 

    } 

  } 

 

  printf("Tutor não encontrado.\n"); 

  aguardarTecla(); 

} 

 

// Exclui um pet de um tutor 

void excluirPet(Tutor donos[MAX_TUTORES], int qtdDonos) { 

  char cpfBusca[15], nomeExcluir[50]; 

  printf("Informe o CPF do tutor do pet: "); 

  limparBuffer(); 

  fgets(cpfBusca, sizeof(cpfBusca), stdin); 

  cpfBusca[strcspn(cpfBusca, "\n")] = '\0'; 

 

  for (int i = 0; i < qtdDonos; i++) { 

    if (strcmp(donos[i].cpf, cpfBusca) == 0) { 

      printf("Nome do pet a ser excluído: "); 

      fgets(nomeExcluir, sizeof(nomeExcluir), stdin); 

      nomeExcluir[strcspn(nomeExcluir, "\n")] = '\0'; 

 

      for (int j = 0; j < donos[i].totalAnimais; j++) { 

        if (strcmp(donos[i].animais[j].nome, nomeExcluir) == 0) { 

          for (int k = j; k < donos[i].totalAnimais - 1; k++) { 

            donos[i].animais[k] = donos[i].animais[k + 1]; 

          } 

          donos[i].totalAnimais--; 

          printf("Pet excluído com sucesso!\n"); 

          aguardarTecla(); 

          return; 

        } 

      } 

 

      printf("Pet não encontrado.\n"); 

      aguardarTecla(); 

      return; 

    } 

  } 

 

  printf("Tutor não encontrado.\n"); 

  aguardarTecla(); 

} 

 

int main() { 

  Tutor donos[MAX_TUTORES]; // Vetor para armazenar os tutores 

  int qtdDonos = 0; // Quantidade atual de tutores cadastrados 

  int opcao; // Armazena a opção do usuário no menu 

 

  do { 

    limparTela(); 

    exibirMenu(); 

    scanf("%d", &opcao); 

    limparBuffer(); 

    limparTela(); 

 

    switch (opcao) { 

      case 1: listarTutores(donos, qtdDonos); break; 

      case 2: cadastrarTutor(donos, &qtdDonos); break; 

      case 3: atualizarTutor(donos, &qtdDonos); break; 

      case 4: excluirTutor(donos, &qtdDonos); break; 

      case 5: listarPets(donos, qtdDonos); break; 

      case 6: cadastrarPet(donos, qtdDonos); break; 

      case 7: atualizarPet(donos, qtdDonos); break; 

      case 8: excluirPet(donos, qtdDonos); break; 

      case 0: printf("Encerrando o programa...\n"); break; 

      default: printf("Opção inválida!\n"); aguardarTecla(); 

    } 

  } while (opcao != 0); 

 

  return 0; 

} 