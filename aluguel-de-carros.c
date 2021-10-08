// BRAYA Rent a Car

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {  // struct de endereco
    char bairro[32], rua[32];
    char casa[32], cep[32];
} Endereco;

typedef struct {  // struct de documentos
    char rg[32];
    char cpf[32];
} Docs;

typedef struct {  // struct de carro
    char marca[32], modelo[32], cor[32], placa[32];
    char status[32];  // Status (Livre, alugado ou revisao)
    float valorDiaria;
} Carro;

typedef struct {  // struct de funcionario
    char nome[32];
    int matricula;
    char cargo[32];
    char telefone[32];
    char login[32], senha[32];
    Endereco endereco;
    Docs docs;
} Funcionario;

typedef struct {  // struct de cliente
    char nome[32];
    char telefone[32];
    int carroAlugado_id;
    int temCarro;
    Docs docs;
    Endereco endereco;
} Cliente;

// Declaracoes das structs
Carro carro[32];
Funcionario funcionario[32];
Cliente cliente[32];

// Contadores gerais
int cont_carro = 0;
int cont_cliente = 0;
int cont_funcionario = 0;

// Declaracao de funcoes
void cadastrarCarro();

void cadastrarCliente();

void cadastrarFuncionario();

void listarCarros();

void realizarAluguel();

void devolucaoCarro();

void gerarRelatorio();

void liberarCarro();

int loginSenha();

int main(void) {
    system("color 0A");
    system("cls");

    char login[32], senha[32];
    int perf = 0;
    int i_adm, i, j, opc;
    int i_adm_cadastro;
    int i_adm_menu_cadastro;
    char cpf_cliente[32];
    int escolhaCarro;
    int diasAluguel;
    float totalAluguel;
    int formaPagamento;
    int pagamentoFinalizado;
    float valorRecebido;
    int id_funcionario;
    int opc_funcionarios;

    for (int err = 0; err < 5; err++) {
        cliente[err].carroAlugado_id = 777;
    }

    system("title BRAYA Rent a Car");

    do {
        printf("\n[1] - Login\n");
        printf("[0] - Sair do programa\n> ");

        scanf("%d", &opc);

        switch (opc) {
            case 1:

                // strcpy(login, "");
                // strcpy(senha, "");

                system("cls");
                // MENU
                printf("\nLogin: ");
                fflush(stdin);
                gets(login);
                // scanf("%s", login);

                printf("Senha: ");
                fflush(stdin);
                gets(senha);
                // scanf("%s", senha);

                system("cls");

                // loginSenha(login, senha);
                // perf = loginSenha(login, senha);

                // MENU

                // ADMIN
                if (strcmp(login, "ADM") == 0 && strcmp(senha, "123") == 0) {
                    fflush(stdin);
                    perf = 1;
                }

                // Atendente
                for (i = 0; i < 32; i++) {
                    if (strcmp(login, funcionario[i].login) == 0 &&
                        strcmp(senha, funcionario[i].senha) == 0 &&
                        strcmp(funcionario[i].cargo, "Atendente") == 0) {
                        id_funcionario = i;
                        perf = 2;
                    }
                }

                // Mecanico
                for (i = 0; i < 32; i++) {
                    if (strcmp(login, funcionario[i].login) == 0 &&
                        strcmp(senha, funcionario[i].senha) == 0 &&
                        strcmp(funcionario[i].cargo, "Mecanico") == 0) {
                        id_funcionario = i;
                        perf = 3;
                    }
                }

                // for (i = 0; i < 32; i++) {
                //     if (strcmp(login, funcionario[i].login) == 0 && strcmp(senha, funcionario[i].senha) == 0) {
                //         id_funcionario = i;

                //         if (strcmp(funcionario[i].cargo, "Atendente") == 0) {
                //             fflush(stdin);
                //             perf = 2;

                //         } else if (strcmp(funcionario[i].cargo, "Mecanico") == 0) {
                //             fflush(stdin);
                //             perf = 3;
                //         }
                //     }
                // }

                switch (perf) {
                    case 1:  // Admin
                        ////////////////

                        printf("\nPagina de administrador\n");

                        do {
                            printf("\n[1] - Cadastrar\n");
                            printf("[2] - Realizar aluguel\n");
                            printf("[3] - Devolucao de carro\n");
                            printf("[4] - Gerar relatorio\n");
                            printf("[0] - Fazer logoff\n> ");

                            scanf("%d", &i_adm);

                            system("cls");

                            switch (i_adm) {
                                case 1:  // Menu de cadastro
                                    do {
                                        i_adm_menu_cadastro = 1;
                                        printf("\n[1] - Cadastrar carro\n");
                                        printf("[2] - Cadastrar cliente\n");
                                        printf("[3] - Cadastrar funcionario\n");
                                        printf("[0] - Menu anterior\n> ");
                                        scanf("%d", &i_adm_cadastro);

                                        system("cls");

                                        switch (i_adm_cadastro) {
                                            case 1:  // Cadastrar carro

                                                cadastrarCarro();
                                                break;

                                            case 2:  // Cadastrar cliente

                                                cadastrarCliente();
                                                break;

                                            case 3:  // Cadastrar funcionario

                                                cadastrarFuncionario();
                                                break;

                                            case 0:

                                                printf("\nVoltando para o menu anterior.\n");
                                                i_adm_menu_cadastro = 0;
                                                break;

                                            default:

                                                printf("Opcao invalida, tente novamente.\n");
                                                break;
                                        }
                                    } while (i_adm_menu_cadastro != 0);
                                    break;

                                case 2:  // Relizar aluguel

                                    realizarAluguel();
                                    break;

                                case 3:  // Devolucao de carro

                                    devolucaoCarro();
                                    break;

                                case 4:  // Gerar relatorio
                                    system("cls");
                                    gerarRelatorio();
                                    break;

                                case 0:  // Sair do adm

                                    printf("\nSaindo do perfil de adm...\n");
                                    i_adm = 0;
                                    perf = 0;
                                    break;

                                default:
                                    printf("\nOpcao invalida, tente novamente\n");
                            }
                        } while (i_adm != 0);
                        break;

                    case 2:  // Funcionario - Atendente
                        system("cls");

                        if (perf == 2) {
                            printf("\n\tFuncionario: %s - %s\n", funcionario[id_funcionario].nome, funcionario[id_funcionario].cargo);

                            do {
                                printf("\n[1] - Cadastrar cliente\n");
                                printf("[2] - Realizar aluguel\n");
                                printf("[0] - Fazer logoff\n> ");
                                scanf("%d", &opc_funcionarios);

                                switch (opc_funcionarios) {
                                    case 1:  // Cadastrar cliente

                                        cadastrarCliente();

                                        break;

                                    case 2:  // Realizar aluguel7m
                                        system("cls");
                                        realizarAluguel();

                                        break;

                                    case 0:  // Fazer logoff
                                        system("cls");
                                        printf("\n\tSaindo ...\n");
                                        opc_funcionarios = 0;
                                        perf = 0;

                                        break;

                                    default:
                                        system("cls");
                                        printf("\nOpcao invalida, tente novamente\n");
                                }

                            } while (opc_funcionarios != 0);
                        } else {
                            // sem permissao (validacao)
                            exit(0);
                        }

                        break;

                    case 3:  // Funcionario - Mecanico
                        system("cls");
                        printf("\n\tFuncionario: %s - %s\n", funcionario[id_funcionario].nome, funcionario[id_funcionario].cargo);
                        liberarCarro();
                        perf = 0;

                        break;

                    case 0:
                        system("cls");
                        printf("\nUsuario ou senha incorreta.\nTente novamente.\n");
                        break;

                    default:
                        system("cls");
                        printf("Usuario ou senha incorreta.\nTente novamente.\n");
                }

                break;

            case 2:  // debug smth
                printf("\n\n%d\n\n", cont_carro);
                break;
                /*
                Cozinhe o macarrão instantâneo normalmente.
                Em uma panela, coloque a manteiga, o tomate, 
                a cebola e o tempero em pó do macarrão instantâneo 
                para fritar, sempre mexendo bem para não empelotar.
                Depois despeje o creme de leite e misture o molho ao macarrão instantâneo.
                */

            case 0:
                system("cls");

                printf("\nSaindo ...\n");

                return 0;
                break;

            default:
                system("cls");
                printf("Opcao invalida, tente novamente...\n");
        }
        // printf("debug");
    } while (opc != 0);

    return 0;
};

// FUNCOES

void cadastrarCarro() {
    char placa_temp[32];
    int i;
    float valorDiaria_temp;

    if (cont_carro == 31) {
        printf("Maximo de carros cadastrados.");
        return;
    }

    printf("Marca: ");
    fflush(stdin);
    gets(carro[cont_carro].marca);

    printf("Modelo: ");
    fflush(stdin);
    gets(carro[cont_carro].modelo);

    printf("Cor: ");
    fflush(stdin);
    gets(carro[cont_carro].cor);

    printf("Placa: ");
    fflush(stdin);
    gets(placa_temp);

    for (i = 0; i < 32; i++) {
        if (strcmp(carro[i].placa, placa_temp) == 0) {
            printf("\nPlaca ja esta em um carro registrado.\n");
            printf("Tente novamente.\n");
            return;
        }
    }

    strcpy(carro[cont_carro].placa, placa_temp);

    strcpy(carro[cont_carro].status, "Livre");

    printf("Valor da diaria: ");
    scanf("%f", &carro[cont_carro].valorDiaria);
    // scanf("%f", &valorDiaria_temp);

    cont_carro++;

    return;
};

void cadastrarCliente() {
    int i;
    char cpf_temp[32];
    char rg_temp[32];

    if (cont_cliente == 31) {
        printf("\nMaximo de clientes cadastrados.\n");
    }

    // Limpando cpf e rg pra nao ler duas vezes
    strcpy(cliente[cont_cliente].docs.rg, " ");
    strcpy(cliente[cont_cliente].docs.cpf, " ");

    printf("Nome: ");
    fflush(stdin);
    gets(cliente[cont_cliente].nome);

    // CPF
    printf("CPF: ");
    fflush(stdin);
    gets(cpf_temp);

    for (i = 0; i < 32; i++) {
        if (strcmp(cpf_temp, cliente[i].docs.cpf) == 0) {
            printf("\nCPF ja cadastrado.\n");
            printf("Tente fazer o cadastro novamente...\n");
            return;
        }
    }

    strcpy(cliente[cont_cliente].docs.cpf, cpf_temp);

    // RG
    printf("RG: ");
    fflush(stdin);
    gets(rg_temp);

    for (i = 0; i < 32; i++) {
        if (strcmp(rg_temp, cliente[i].docs.rg) == 0) {
            printf("\nRG ja cadastrado\nTente fazer o cadastro novamente....");
            return;
        }
    }

    strcpy(cliente[cont_cliente].docs.rg, rg_temp);

    printf("Telefone: ");
    fflush(stdin);
    gets(cliente[cont_cliente].telefone);

    printf("Bairro: ");
    fflush(stdin);
    gets(cliente[cont_cliente].endereco.bairro);

    printf("Rua: ");
    fflush(stdin);
    gets(cliente[cont_cliente].endereco.rua);

    printf("Casa: ");
    fflush(stdin);
    gets(cliente[cont_cliente].endereco.casa);

    printf("CEP: ");
    fflush(stdin);
    gets(cliente[cont_cliente].endereco.cep);

    cont_cliente++;

    return;
};

void cadastrarFuncionario() {
    int i;
    char login_temp[32];
    char rg_temp[32], cpf_temp[32];
    int opc;

    if (cont_funcionario == 31) {
        printf("\nMaximo de funcionarios cadastrados.\n");
        return;
    }

    fflush(stdin);

    // Limpando login, rg e cpf pra n ler repetido
    strcpy(funcionario[cont_funcionario].login, " ");
    strcpy(funcionario[cont_funcionario].docs.rg, " ");
    strcpy(funcionario[cont_funcionario].docs.cpf, " ");

    do {
        printf("\n[1] - Atendente\n");
        printf("[2] - Mecanico\n");
        printf("[0] - Sair\n> ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                strcpy(funcionario[cont_funcionario].cargo, "Atendente");
                opc = 0;
                break;
            case 2:
                strcpy(funcionario[cont_funcionario].cargo, "Mecanico");
                opc = 0;
                break;
            case 0:
                return;
                break;
            default:
                printf("Opcao invalida");
        }
    } while (opc != 0);

    printf("Nome: ");
    fflush(stdin);
    gets(funcionario[cont_funcionario].nome);
    // scanf("%s", funcionario[cont_funcionario].nome);

    // Login
    printf("Login: ");
    fflush(stdin);
    gets(login_temp);
    // scanf("%s", login_temp);

    for (i = 0; i < 32; i++) {
        if (strcmp(login_temp, funcionario[i].login) == 0 || strcmp(login_temp, "ADM") == 0) {
            printf("Login ja esta em uso.\n");
            printf("Tente fazer o cadastro novamente.\n\n");
            return;
        }
    }

    strcpy(funcionario[cont_funcionario].login, login_temp);

    printf("Senha: ");
    fflush(stdin);
    gets(funcionario[cont_funcionario].senha);
    // scanf("%s", funcionario[cont_funcionario].senha);

    // RG
    printf("RG: ");
    fflush(stdin);
    gets(rg_temp);
    // scanf("%s", rg_temp);

    for (i = 0; i < 32; i++) {
        if (strcmp(rg_temp, funcionario[i].docs.rg) == 0) {
            printf("RG ja cadastrado.\n");
            printf("Tente cadastrar novamente.\n");
            return;
        }
    }

    strcpy(funcionario[cont_funcionario].docs.rg, rg_temp);

    // CPF
    printf("CPF: ");
    fflush(stdin);
    gets(cpf_temp);
    // scanf("%s", cpf_temp);

    for (i = 0; i < 32; i++) {
        if (strcmp(cpf_temp, funcionario[i].docs.cpf) == 0) {
            printf("CPF ja cadastrado.\n");
            printf("Tente cadastrar novamente.\n");
            return;
        }
    }

    strcpy(funcionario[cont_funcionario].docs.cpf, cpf_temp);

    printf("Telefone: ");
    fflush(stdin);
    gets(funcionario[cont_funcionario].telefone);
    // scanf("%s", funcionario[cont_funcionario].telefone);

    printf("Bairro: ");
    fflush(stdin);
    gets(funcionario[cont_funcionario].endereco.bairro);
    // scanf("%s", funcionario[cont_funcionario].endereco.bairro);

    printf("Rua: ");
    fflush(stdin);
    gets(funcionario[cont_funcionario].endereco.rua);
    // scanf("%s", funcionario[cont_funcionario].endereco.rua);

    printf("Casa: ");
    fflush(stdin);
    gets(funcionario[cont_funcionario].endereco.casa);
    // scanf("%s", funcionario[cont_funcionario].endereco.casa);

    printf("CEP: ");
    fflush(stdin);
    gets(funcionario[cont_funcionario].endereco.cep);
    // scanf("%s", funcionario[cont_funcionario].endereco.cep);

    funcionario[cont_funcionario].matricula = cont_funcionario + 1;

    cont_funcionario++;

    fflush(stdin);

    return;
};

/*
int loginSenha(char login[32], char senha[32]) {
    int i;
    fflush(stdin);
    if (strcmp(login, "ADM") == 0 && strcmp(senha, "123") == 0) {
        return 1;
    }
    for (i = 0; i < 32; i++) {
        if (strcmp(login, funcionario[i].login) == 0 &&
            strcmp(senha, funcionario[i].senha) == 0 &&
            strcmp(funcionario[i].cargo, "Atendente") == 0) {
            return 2;
        }
    }
    for (i = 0; i < 32; i++) {
        if (strcmp(login, funcionario[i].login) == 0 &&
            strcmp(senha, funcionario[i].senha) == 0 &&
            strcmp(funcionario[i].cargo, "Mecanico") == 0) {
            return 3;
        }
    }
    return 0;
};
*/

void realizarAluguel() {
    char cpf_cliente[32];
    int i, j, escolhaCarro, diasAluguel, formaPagamento, pagamentoFinalizado;
    float totalAluguel, valorRecebido;
    int controle_aluguel = 0;
    int confirmarAluguel;

    if (cont_carro == 0) {
        printf("\nNao existem carros cadastrados.\n");
        return;
    }

    if (cont_cliente == 0) {
        printf("\nNao existem clientes cadastrados.\n");
        return;
    }

    for (i = 0; i < 32; i++) {
        if (strcmp(carro[i].status, "Livre") == 0) {
            controle_aluguel = 1;
        }
    }

    if (controle_aluguel == 0) {
        printf("\nNao existem carros no patio.\n");
        return;
    }

    printf("Informe o CPF do cliente: ");
    fflush(stdin);
    gets(cpf_cliente);

    for (i = 0; i < 32; i++) {
        if (strcmp(cpf_cliente, cliente[i].docs.cpf) == 0) {
            j = i;
        }
    }

    if (cliente[j].temCarro == 1) {
        printf("\nEste cliente ja possui um carro em seu nome.\n");
        printf("\nSomente um carro por CPF\n");
        return;
    }

    printf("\nCliente: %s\n", cliente[j].nome);

    for (i = 0; i < 32; i++) {
        if (strcmp(carro[i].status, "Livre") == 0) {
            // Mostrar carros somente com o status -livre-
            printf("\nCarro %d\n", i + 1);
            printf("Marca: %s\nModelo: %s\nCor: %s\nStatus: %s\nDiaria (R$): %.2f\n",
                   carro[i].marca,
                   carro[i].modelo,
                   carro[i].cor,
                   carro[i].status,
                   carro[i].valorDiaria);
        }
    }

    printf("\nNumero do carro para alguel: ");
    scanf("%d", &escolhaCarro);

    escolhaCarro = escolhaCarro - 1;

    if (escolhaCarro > cont_carro) {
        printf("\nEste carro ainda nao foi cadastrado\nTente novamente mais tade.\n");
        return;
    }

    for (i = 0; i < 32; i++) {
        if (strcmp(carro[escolhaCarro].status, "Livre") != 0) {
            printf("\nEste carro nao esta disponivel para aluguel.\nTente novamente mais tarde.\n");
            return;
        }
    }

    printf("Dias de alguel: ");
    scanf("%d", &diasAluguel);

    totalAluguel = diasAluguel * carro[escolhaCarro].valorDiaria;

    printf("\nTotal: %.2f", totalAluguel);

    printf("\nConfirmar aluguel ?\n");
    printf("[1] - Sim\n");
    printf("[2] - Nao\n> ");
    scanf("%d", &confirmarAluguel);

    do {
        switch (confirmarAluguel) {
            case 1:
                confirmarAluguel = 2;
                break;
            case 2:
                return;
                break;
            default:
                printf("\nOpcao invalida, tente novamente\n");
        }
    } while (confirmarAluguel != 2);

    do {
        printf("\nForma de pagamento\n");
        printf("[1] - Dinheiro\n");
        printf("[2] - Debito\n");
        printf("[3] - Credito\n");

        scanf("%d", &formaPagamento);

        switch (formaPagamento) {
            case 1:
                printf("\nValor recebido: ");
                scanf("%f", &valorRecebido);

                if (valorRecebido < totalAluguel) {
                    printf("Valor recebido nao cobre o total.");
                    break;
                } else {
                    printf("Troco: R$ %.2f\n\n", valorRecebido - totalAluguel);
                    pagamentoFinalizado = 0;
                }

                system("pause");

                pagamentoFinalizado = 0;
                break;

            case 2:
                pagamentoFinalizado = 0;
                break;

            case 3:
                pagamentoFinalizado = 0;
                break;

            default:
                printf("Opcao invalida");
        }

    } while (pagamentoFinalizado != 0);

    system("cls");

    printf("\nBRAYA Rent a Car prestadora de servico de aluguel, remediar ao %s, portador do RG: %s, portador do CPF: %s, residindo no Bairro: %s, rua: %s, casa: %s, cep: %s, com contato: %s. O veiculo modelo: %s, marca: %s, placa: %s, cor: %s. Desta forma o valor total deste termo e: R$ %.2f, referente ao total de dia(s): %d, com valor da diaria: R$ %.2f\n\n",
           cliente[j].nome,
           cliente[j].docs.rg,
           cliente[j].docs.cpf,
           cliente[j].endereco.bairro,
           cliente[j].endereco.rua,
           cliente[j].endereco.casa,
           cliente[j].endereco.cep,
           cliente[j].telefone,
           carro[escolhaCarro].modelo,
           carro[escolhaCarro].marca,
           carro[escolhaCarro].placa,
           carro[escolhaCarro].cor,
           totalAluguel,
           diasAluguel,
           carro[escolhaCarro].valorDiaria);

    system("pause");

    cliente[j].temCarro = 1;

    cliente[j].carroAlugado_id = escolhaCarro;
    strcpy(carro[escolhaCarro].status, "Alugado");
};

void devolucaoCarro() {
    char cpf_cliente[32];
    int i, j, id_carro;
    int statusAfter;

    if (cont_cliente == 0) {
        printf("\nNao existem clientes cadastrados.\n");
        return;
    }

    printf("CPF do cliente: ");
    fflush(stdin);
    gets(cpf_cliente);

    for (i = 0; i < 32; i++) {
        if (strcmp(cpf_cliente, cliente[i].docs.cpf) == 0) {
            j = i;
        }
    }

    id_carro = cliente[j].carroAlugado_id;

    if (cliente[j].carroAlugado_id == 777) {
        printf("\nO usuario nao possui nenhum carro em seu nome.\n");
        return;
    }

    printf("\n\tDados do carro\n\n");
    printf("Marca: %s\nModelo: %s\nCor: %s\nPlaca: %s\nDiaria: R$%.2f",
           carro[id_carro].marca,
           carro[id_carro].modelo,
           carro[id_carro].cor,
           carro[id_carro].placa,
           carro[id_carro].valorDiaria);

    do {
        printf("\n[1] - Patio\n");
        printf("[2] - Revisao\n");
        printf("Opcao: ");
        scanf("%d", &statusAfter);

        switch (statusAfter) {
            case 1:
                strcpy(carro[id_carro].status, "Livre");
                statusAfter = 0;
                printf("\nO carro foi devolvido ao patio.\n");
                cliente[id_carro].carroAlugado_id = 777;
                break;

            case 2:
                strcpy(carro[id_carro].status, "Revisao");
                statusAfter = 0;
                printf("\nO carro foi mandado para revisao\n");
                cliente[id_carro].carroAlugado_id = 777;
                break;

            default:
                printf("\nOpcao invalida.\n");
        }
    } while (statusAfter != 0);
    cliente[j].temCarro = 0;
};

void gerarRelatorio() {
    int relatorioOpc, i;
    int controle_patio = 0;
    int controle_alugado = 0;
    int controle_revisao = 0;
    printf("\n\tMenu de relatorios");

    do {
        system("cls");
        printf("\n[1] - Carros no patio\n");
        printf("[2] - Carros alugados\n");
        printf("[3] - Carros na revisao\n");
        printf("[0] - Menu anterior\n> ");
        scanf("%d", &relatorioOpc);

        system("cls");

        switch (relatorioOpc) {
            case 1:
                controle_patio = 0;
                for (i = 0; i < 32; i++) {
                    if (strcmp(carro[i].status, "Livre") == 0) {
                        controle_patio = 1;
                    }
                }

                if (controle_patio == 0) {
                    printf("\nNao existem carros no patio.\n");
                    system("pause");
                    break;
                }

                // Relatorio patio
                for (i = 0; i < 32; i++) {
                    if (strcmp(carro[i].status, "Livre") == 0) {
                        printf("\nCarro %d\n", i + 1);
                        //marca modelo cor placa status diaria
                        printf("Marca: %s\nModelo: %s\nCor: %s\nPlaca: %s\nStatus: %s\nDiaria: R$ %.2f\n\n",
                               carro[i].marca,
                               carro[i].modelo,
                               carro[i].cor,
                               carro[i].placa,
                               carro[i].status,
                               carro[i].valorDiaria);
                    }
                }
                printf("\n");
                system("pause");
                break;
            case 2:
                relatorioOpc = 1;
                controle_alugado = 0;
                for (i = 0; i < 32; i++) {
                    if (strcmp(carro[i].status, "Alugado") == 0) {
                        controle_alugado = 1;
                    }
                }

                if (controle_alugado == 0) {
                    printf("\nNao existem carros alugados.\n");
                    system("pause");
                    break;
                }

                // Relatorio alugados
                for (i = 0; i < 32; i++) {
                    if (strcmp(carro[i].status, "Alugado") == 0) {
                        printf("\nCarro %d\n", i + 1);
                        //marca modelo cor placa status diaria
                        printf("Marca: %s\nModelo: %s\nCor: %s\nPlaca: %s\nStatus: %s\nDiaria: R$ %.2f\n\n",
                               carro[i].marca,
                               carro[i].modelo,
                               carro[i].cor,
                               carro[i].placa,
                               carro[i].status,
                               carro[i].valorDiaria);
                    }
                }
                system("pause");
                break;

            case 3:
                controle_revisao = 0;

                for (i = 0; i < 32; i++) {
                    if (strcmp(carro[i].status, "Revisao") == 0) {
                        controle_revisao = 1;
                    }
                }

                if (controle_revisao == 0) {
                    printf("\nNao existem carros na revisao.\n");
                    system("pause");
                    break;
                }

                // Relatorio revisao
                for (i = 0; i < 32; i++) {
                    if (strcmp(carro[i].status, "Revisao") == 0) {
                        printf("\nCarro %d\n", i + 1);
                        //marca modelo cor placa status diaria
                        printf("Marca: %s\nModelo: %s\nCor: %s\nPlaca: %s\nStatus: %s\nDiaria: R$ %.2f\n\n",
                               carro[i].marca,
                               carro[i].modelo,
                               carro[i].cor,
                               carro[i].placa,
                               carro[i].status,
                               carro[i].valorDiaria);
                    }
                }
                system("pause");
                break;

            case 0:
                relatorioOpc = 0;
                break;

            default:
                printf("\nOpcao invalida\n");
                system("pause");
        }
    } while (relatorioOpc != 0);
};

void liberarCarro() {
    int i, opc, id_liberar, temRevisao = 0;
    int controle_mecanico;

    do {
        printf("\n[1] - Listar carros na revisao\n");
        printf("[0] - Fazer logoff\n");
        scanf("%d", &controle_mecanico);

        switch (controle_mecanico) {
            case 1:

                if (cont_carro == 0) {
                    printf("\nNao existem carros na revisao.\n");
                    break;
                }

                for (i = 0; i < 32; i++) {
                    if (strcmp(carro[i].status, "Revisao") == 0) {
                        temRevisao = 1;
                    }
                }

                if (temRevisao == 0) {
                    printf("\nNao existem carros na revisao.\n");
                    break;
                }

                for (i = 0; i < 32; i++) {
                    if (strcmp(carro[i].status, "Revisao") == 0) {
                        printf("\n\tCarro: %d\n", i + 1);
                        printf("Marca: %s\nModelo: %s\nCor: %s\nPlaca: %s\nStatus: %s\n",
                               carro[i].marca,
                               carro[i].modelo,
                               carro[i].cor,
                               carro[i].placa,
                               carro[i].status);
                    }
                }
                do {
                    printf("\n[1] - Liberar carro\n");
                    printf("[0] - Logoff\n> ");
                    scanf("%d", &opc);

                    switch (opc) {
                        case 1:
                            printf("Numero do carro para liberar: ");
                            scanf("%d", &id_liberar);

                            if (id_liberar > cont_carro) {
                                printf("\nEste carro ainda nao foi cadastrado\n\n");
                                break;
                            }

                            id_liberar -= 1;

                            if (strcmp(carro[id_liberar].status, "Revisao") != 0) {
                                printf("\nEste carro nao esta na revisao.\n\n");
                                break;
                            }

                            strcpy(carro[id_liberar].status, "Livre");
                            printf("Carro %d liberado.", id_liberar + 1);
                            break;
                        case 0:
                            printf("\nMenu anterior\n");
                            opc = 0;
                            break;
                        default:
                            printf("\nOpcao invalida\n");
                    }
                } while (opc != 0);

                break;
            case 0:
                controle_mecanico = 0;
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida, tente novamente.\n");
        }
    } while (controle_mecanico != 0);
};