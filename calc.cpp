#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <iomanip>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::fixed;
using std::setprecision;

void calc(int*, int*);
void pagMais(double);

int main(){
    /*int x, y;
    cout << "Digite dois numeros" << endl;
    cin >> x >> y;
    calc(&x, &y);//passando como referência*/
    
    double salario;
    cout << "Qual o seu salario?";
    cin >> salario;
    pagMais(salario);
    return 0;
}

//Função que faz várias operações
void calc(int* num1, int* num2){//passa 2 ponteiros como parâmetros
    string SN = "n";
    int cont[20], conta=0;
    srand(time(0));//iniciando um gerador de números aleatórios
    for(int i : cont){
        cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        cout << "[1]somar - [2]multiplicar - [3]maior - [4]novos valores" << endl;
        cin >> conta;
        cout << "========" << endl;
        cout << "R= ";
        if (conta == 1){
            cout << *num1 << " + " << *num2 << " = "<< *num1 + *num2 << endl;//soma 2 números
        }else if(conta == 2){
            cout << *num1 << " x " << *num2 << " = " << *num1 * *num2 << endl;//multiplica 2 números
        }else if(conta == 3){
            if (*num1 > *num2){
                cout << "Maior numero entre " << *num1 << " e " << *num2 << " = " << *num1 << endl;//aponta o maior número
            }else{
                cout << "Maior numero entre " << *num1 << " e " << *num2 << " = " << *num2 << endl;//aponta o maior número
            }
        }else if(conta == 4){
            *num1 = (1+(rand())%10);//cria números aleatórios
            *num2 = (1+(rand())%10);//cria números aleatórios
            cout << "Novos numeros " << *num1 << " - " << *num2 << endl;//mostra os novos números que foram colocados nos ponteiros
        }else{
            break;
        }
        cout << "deseja continuar? [S/N]" << endl;
        cin >> SN;
        if(SN == "n" || SN == "N"){
            break;
        }else if(SN == "s" || SN == "S"){
            continue;
        }else{
            break;
        }
    }
}

//Função que recebe um salário e diz se o produto que o cliente quer será concedido
void pagMais(double salario){
    string produto, SN;
    double valor_pro, result;
    int parcelas;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "                                  P A G M A I S\n";
    cout << "                                  -=-=-=-=-=-=-\n";
    cout << "                                    BEM-VINDO \n\n" ;

    for (int i = 0; i < 30; i++){
        cout << "Qual o nome do produto que deseja comprar e o seu valor?\n" ;
        cin >> produto >> valor_pro;//recebe o nome do produto e o valor
        cout << "\nEm quantas parcelas pretende pagar? \n" ;
        cin >> parcelas;
        result = valor_pro/parcelas;//valor da parcela do produto
        if (salario * 0.30 < result){//verifica se 30% do salário cobre as parcelas
            cout << "\nDesculpe! Sua compra nao foi aprovada. \n";
        }else{
            cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
            cout << "\nParabens!! Sua compra foi aprovada com sucesso!\n";
            cout << "O seu " << produto << " ficara  por " << parcelas << " parcelas de R$";
            cout << fixed << setprecision(2) << result << endl;
        }
        cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
        cout << "O senhor[a] gostaria de algo mais da loja?[S/N]"<< endl;
        cin >> SN;
        if (SN == "s" || SN == "S"){
            continue;
        }else if (SN == "n" || SN == "N"){
            break;
        }else{
            break;
        }
    }
}