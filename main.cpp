#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;
using std::string;
using std::vector;
 
///////Classes\\\\\\\*
 
class Veiculo
{
private:
    int codigo;
    string modelo;
    string cor;
    int ano;
    int odometro;
    string cidade;
    char disponivel;
    float valorDiaria;
    float valorKmRodado;
 
public:
    char getdisponivel() { return this->disponivel; };
    float getvalorDiaria() { return this->valorDiaria; };
    float getvalorKmRodado() { return this->valorKmRodado; };
 
    Veiculo(string linha)
    {
        stringstream ss(linha);
        ss >> this->codigo;
        ss.ignore(1);
        getline(ss, this->modelo, '\t');
        getline(ss, this->cor, '\t');
        ss >> this->ano;
        ss.ignore(1);
        ss >> this->odometro;
        ss.ignore(1);
        getline(ss, this->cidade, '\t');
        ss >> this->disponivel, '\t';
        ss >> this->valorDiaria;
        ss.ignore(1);
        ss >> this->valorKmRodado;
    }
   string serializarVeiculos()
    {
        stringstream vv;
        vv << this->codigo << '\t'
           << this->modelo << '\t'
           << this->cor << '\t'
           << this->ano << '\t'
           << this->odometro << '\t'
           << this->cidade << '\t'
           << this->disponivel << '\t'
           << this->valorDiaria << '\t'
           << this->valorKmRodado;
 
        return vv.str();
    }
    void imprimeDados()
    {
        cout << "Codigo: " << this->codigo << endl;
        cout << "Modelo: " << this->modelo << endl;
        cout << "cor: " << this->cor << endl;
        cout << "ano: " << this->ano << endl;
        cout << "Odometro: " << this->odometro << endl;
        cout << "Cidade: " << this->cidade << endl;
        cout << "Disponivel: " << this->disponivel << endl;
        cout << "Valor Diaria: " << this->valorDiaria << endl;
        cout << "Valor KM Rodado: " << this->valorKmRodado << endl;
    }
    void setCodigo(int codigo)
    {
        this->codigo = codigo;
    }
    int getCodigo()
    {
        return this->codigo;
    }
    void setModelo(string modelo)
    {
        this->modelo = modelo;
    }
    string getModelo()
    {
        return this->modelo;
    }
    void setCor(string cor)
    {
        this->cor = cor;
    }
    string getCor()
    {
        return this->cor;
    }
    void setAno(int ano)
    {
        this->ano = ano;
    }
    int getAno()
    {
        return this->ano;
    }
    void setOdometro(int odometro)
    {
        this->odometro = odometro;
    }
    int getOdometro()
    {
        return this->odometro;
    }
    void setCidade(string cidade)
    {
        this->cidade = cidade;
    }
    string getCidade()
    {
        return this->cidade;
    }
    void setDisponivel(char disponivel)
    {
        this->disponivel = disponivel;
    }
    char getDisponivel()
    {
        return this->disponivel;
    }
    void setValorDiaria(float valorDiaria)
    {
        this->valorDiaria = valorDiaria;
    }
    float getValorDiaria()
    {
        return this->valorDiaria;
    }
    void setValorKmRodado(float valorKmRodado)
    {
        this->valorKmRodado = valorKmRodado;
    }
    float getValorKmRodado()
    {
        return this->valorKmRodado;
    }
};
class Locacao
{
private:
    Veiculo *veiculo;
    int codVeiculo;
    string cliente;
    string origem;
    string destino;
    int kmRodado;
    int qtDiasReserva;
    int qtDiasRealizado;
 
public:
    Locacao(string linha)
    {
        string dado;
        stringstream ss(linha);
        ss >> this->codVeiculo;
        ss.ignore(1);
        getline(ss, this->cliente, '\t');
        getline(ss, this->origem, '\t');
        getline(ss, this->destino, '\t');
        getline(ss, dado, '\t');
        if (dado.empty())
            this->kmRodado = 0;
        else
            this->kmRodado = stoi(dado);
        ss >> this->qtDiasReserva;
        ss.ignore(1);
        getline(ss, dado, '\t');
        if (dado.empty())
            this->qtDiasRealizado = 0;
        else
            this->qtDiasRealizado = stoi(dado);
    }
    string serializarLocacoes()
    {
        stringstream ll;
        ll << this->codVeiculo << '\t'
           << this->cliente << '\t'
           << this->origem << '\t'
           << this->destino << '\t'
           << this->kmRodado << '\t'
           << this->qtDiasReserva << '\t'
           << this->qtDiasRealizado;
 
        return ll.str();
    }
    void setVeiculo(Veiculo *veiculo)
    {
        this->veiculo = veiculo;
    }
    void setCodVeiculo(int codVeiculo)
    {
        this->codVeiculo = codVeiculo;
    }
    void setCliente(string cliente)
    {
        this->cliente = cliente;
    }
    void setOrigem(string origem)
    {
        this->origem = origem;
    }
    void setDestino(string destino)
    {
        this->destino = destino;
    };
    void setKmRodado(int kmRodado)
    {
        this->kmRodado = kmRodado;
    };
    void setqtdDiasReserva(int qtDiasReserva)
    {
        this->qtDiasReserva = qtDiasReserva;
    };
    void setqtDiasRealizado(int qtDiasRealizado)
    {
        this->qtDiasRealizado = qtDiasRealizado;
    }
    Veiculo *getVeiculo()
    {
        return this->veiculo;
    }
    string getCliente()
    {
        return this->cliente;
    }
    string getOrigem()
    {
        return this->origem;
    }
    string getDestino()
    {
        return this->destino;
    }
    int getkmRodado()
    {
        return this->kmRodado;
    }
    int getqtdDiasReserva()
    {
        return this->qtDiasReserva;
    }
    int getqtDiasRealizado()
    {
        return this->qtDiasRealizado;
    }
    int getCodVeiculo()
    {
        return this->codVeiculo;
    }
    void imprimeDados()
    {
        cout << "Veículo: " << this->codVeiculo << endl;
        cout << "Cliente: " << this->cliente << endl;
        cout << "Origem: " << this->origem << endl;
        cout << "Destino: " << this->destino << endl;
        cout << "km Rodado: " << this->kmRodado << endl;
        cout << "Dias reservados: " << this->qtDiasReserva << endl;
        cout << "Dias realizados: " << this->qtDiasRealizado << endl;
    }
};
class Locadora
{
private:
    vector<Veiculo *> veiculos;
    vector<Locacao *> locacoes;
 
public:
    Veiculo *getVeiculoCodigo(int codigo)
    {
        vector<Veiculo *>::iterator it;
        for (it = veiculos.begin(); it != veiculos.end(); it++)
        {
            if ((*it)->getCodigo() == codigo)
            {
                return *it;
            }
        }
        return NULL;
    }
    void realizaLocacao()
    {
        float valorDiaria = 15;
        string nomeClienteMaiusculo;
        float valorFinal;
        string cidadeEscolha;
        string cidadeEscolhaMaiusculo;
        int codVeiculoDesejado;
        string nomeCliente;
        vector<Veiculo *>::iterator it;
        vector<Locacao *>::iterator lc;
        int limiteReserva = 0;
        int quantidadeDiarias;
        int zerado = 0;
        int a = 0;
        system("cls");
        cout << "----------REALIZAR LOCAÇÃO----------" << endl;
        cout << "\nDigite a Cidade de origem: " << endl;
        fflush(stdin);
        getline(cin, cidadeEscolha);
        system("cls");
        cidadeEscolhaMaiusculo = toupper(cidadeEscolha[0]);
        for (int i = 1; i < cidadeEscolha.length(); i++)
        {
            cidadeEscolhaMaiusculo += cidadeEscolha[i];
        }
        cout << "Cidade Escolhida: " << cidadeEscolhaMaiusculo << endl;
 
        for (it = veiculos.begin(); it != veiculos.end(); it++)
        {
            if ((*it)->getCidade() == cidadeEscolhaMaiusculo && (*it)->getDisponivel() == 'S')
            {
                (*it)->imprimeDados();
                cout << "\n"
                     << endl;
                a++;
            }
            else if ((*it)->getCidade() == cidadeEscolhaMaiusculo && (*it)->getDisponivel() == 'N')
            {
                cout << "NENHUM VEICULO DISPONIVEL PARA A CIDADE SELECIONADA" << endl;
            }
        }
        if (a >= 1)
        {
            cout << "Digite Seu Nome: " << endl;
            getline(cin, nomeCliente);
            nomeClienteMaiusculo = toupper(nomeCliente[0]);
            for (int i = 1; i < nomeCliente.length(); i++)
            {
                nomeClienteMaiusculo += nomeCliente[i];
            }
            vector<Locacao *>::iterator lc;
            for (lc = locacoes.begin(); lc != locacoes.end(); lc++)
            {
                if ((*lc)->getCliente() == nomeClienteMaiusculo)
                {
                    limiteReserva++;
                }
            }
            if (limiteReserva == 0)
            {
                int escolhaMenu;
                cout << "Digite o codigo do veiculo desejado: " << endl;
                cin >> codVeiculoDesejado;
                cout << "Informe a Quantiade de diarias:  " << endl;
                cin >> quantidadeDiarias;
                vector<Veiculo *>::iterator it;
                for (it = veiculos.begin(); it != veiculos.end(); it++)
                {
                    if ((*it)->getCodigo() == codVeiculoDesejado)
                    {
                        valorDiaria = (*it)->getValorDiaria();
                    }
                }
                valorFinal = quantidadeDiarias * valorDiaria;
                cout << "Valor a pagar: " << valorFinal << endl;
                cout << "(1) Para lugar || (2) Para cancelar" << endl;
                cin >> escolhaMenu;
                if (escolhaMenu == 1)
                {
                    vector<Veiculo *>::iterator it;
                    for (it = veiculos.begin(); it != veiculos.end(); it++)
                    {
                        if ((*it)->getCodigo() == codVeiculoDesejado)
                        {
                            (*it)->setDisponivel('N');
                        }
                    }
                    vector<Locacao *>::iterator ab;
                    for (ab = locacoes.begin(); ab != locacoes.end(); ab++)
                    {
                        if ((*ab)->getCodVeiculo() == codVeiculoDesejado)
                        {
                            (*ab)->setCliente(nomeClienteMaiusculo);
                            (*ab)->setOrigem(cidadeEscolhaMaiusculo);
                            (*ab)->setDestino("Em Viagem");
                            (*ab)->setKmRodado('0');
                            (*ab)->setqtdDiasReserva(quantidadeDiarias);
                            (*ab)->setqtDiasRealizado('0');
                        }
                    }
                }
                else
                {
                    cout << "Reserva cancelada" << endl;
                    system("pause");
                }
            }
            else
            {
                cout << "Só é permitida uma reserva por cliente " << endl;
                system("pause");
            }
        }
    }
    void salvaDados()
    {
        vector<Veiculo *>::iterator itv;
        fstream fvei("C:\\Users\\Arthur pro\\Desktop\\PROJETOLOCADORA\\veiculos.txt", iostream::out | iostream::trunc);
        if (fvei.is_open())
        {
            fvei << "Codigo\tmodelo\tano\todometro\tcidade\tdisponivel\tvalorDiaria\tvalorKmRodado";
            for (itv = veiculos.begin(); itv != veiculos.end(); itv++)
            {
                fvei << endl
                     << (*itv)->serializarVeiculos();
            }
            fvei.close();
            cout << veiculos.size() << " Veiculos salvos no arquivo" << endl;
        }
        vector<Locacao *>::iterator itl;
        fstream floc("C:\\Users\\Arthur pro\\Desktop\\PROJETOLOCADORA\\locacoes.txt", iostream::out | iostream::trunc);
        if (floc.is_open())
        {
            floc << "veiculo\tcliente\torigem\tdestino\tkmRodado\tqtDiasReserva\tqtDiasRealizado";
            for (itl = locacoes.begin(); itl != locacoes.end(); itl++)
            {
                floc << endl << (*itl)->serializarLocacoes();
            }
            floc.close();
            cout << locacoes.size() << " Locações salvas no arquivo" << endl;
        }
        system("pause");
    }
    void consultaVeiculo()
    {
        int escolhaMenu;
        string modeloEscolha;
        string corEscolha;
        int anoEscolha;
        string cidadeEscolha;
        string modeloEscolhaMaiusculo;
        string corEscolhaMaiusculo;
        string cidadeEscolhaMaiusculo;
        while (escolhaMenu != 5)
        {
            system("cls");
            cout << "----------CONSULTA VEICULOS----------" << endl;
            cout << "(1) Consulta Por Modelo" << endl;
            cout << "(2) Consulta Por Cor" << endl;
            cout << "(3) Consulta Por Ano" << endl;
            cout << "(4) Consulta Por Cidade" << endl;
            cout << "(5) Sair" << endl;
            cout << "Digite uma opção: " << endl;
            cin >> escolhaMenu;
            system("cls");
            switch (escolhaMenu)
            {
            case 1:
            {
                cout << "\nDigite o Modelo: " << endl;
                cin >> modeloEscolha;
                system("cls");
                modeloEscolhaMaiusculo = toupper(modeloEscolha[0]);
                for (int i = 1; i < modeloEscolha.length(); i++)
                {
                    modeloEscolhaMaiusculo += modeloEscolha[i];
                }
                vector<Veiculo *>::iterator it;
                for (it = veiculos.begin(); it != veiculos.end(); it++)
                {
                    if ((*it)->getModelo() == modeloEscolhaMaiusculo)
                    {
                        (*it)->imprimeDados();
                        cout << "\t" << endl;
                    }
                }
                system("pause");
            }
            break;
            case 2:
            {
                cout << "\nDigite a Cor: " << endl;
                cin >> corEscolha;
                system("cls");
                corEscolhaMaiusculo = toupper(corEscolha[0]);
                for (int i = 1; i < corEscolha.length(); i++)
                {
                    corEscolhaMaiusculo += corEscolha[i];
                }
                vector<Veiculo *>::iterator it;
                for (it = veiculos.begin(); it != veiculos.end(); it++)
                {
                    if ((*it)->getCor() == corEscolhaMaiusculo)
                    {
                        (*it)->imprimeDados();
                        cout << "\t" << endl;
                    }
                }
                system("pause");
            }
            break;
            case 3:
            {
                cout << "\nDigite o Ano: " << endl;
                cin >> anoEscolha;
                system("cls");
                vector<Veiculo *>::iterator it;
                for (it = veiculos.begin(); it != veiculos.end(); it++)
                {
                    if ((*it)->getAno() == anoEscolha)
                    {
                        (*it)->imprimeDados();
                        cout << "\t" << endl;
                    }
                }
                system("pause");
            }
            break;
            case 4:
            {
                cout << "\nDigite a Cidade: " << endl;
                fflush(stdin);
                getline(cin, cidadeEscolha);
                system("cls");
                cidadeEscolhaMaiusculo = toupper(cidadeEscolha[0]);
                for (int i = 1; i < cidadeEscolha.length(); i++)
                {
                    cidadeEscolhaMaiusculo += cidadeEscolha[i];
                }
                vector<Veiculo *>::iterator it;
                for (it = veiculos.begin(); it != veiculos.end(); it++)
                {
                    if ((*it)->getCidade() == cidadeEscolhaMaiusculo)
                    {
                        (*it)->imprimeDados();
                        cout << "\t" << endl;
                    }
                }
                system("pause");
            }
            break;
            }
        }
    }
    void carregaDados()
    {
        string linha;
        fstream fsv("C:\\Users\\Arthur pro\\Desktop\\PROJETOLOCADORA\\veiculos.txt", iostream::in);
        if (veiculos.size() > 0)
        {
            cout << veiculos.size() << " Veiculos lidos" << endl;
            fsv.close();
        }
        else if (fsv.is_open())
        {
            getline(fsv, linha);
            while (!fsv.eof())
            {
                getline(fsv, linha);
                if (!linha.empty())
                {
                    veiculos.push_back(new Veiculo(linha));
                }
            }
            fsv.close();
            cout << veiculos.size() << " VEICULOS LIDOS" << endl;
        }
        else
            cout << "⚠ Não foi possível ler os Dados|VERIFIQUE O CAMINHO DO ARQUIVO" << endl;
 
        fstream fsl("C:\\Users\\Arthur pro\\Desktop\\PROJETOLOCADORA\\locacoes.txt", iostream::in);
        if (locacoes.size() > 0)
        {
            cout << locacoes.size() << " LOCAÇÕES LIDAS" << endl;
            fsl.close();
        }
        else if (fsl.is_open())
        {
            getline(fsl, linha);
            while (!fsl.eof())
            {
                getline(fsl, linha);
                if (!linha.empty())
                {
                    Locacao *l = new Locacao(linha);
                    l->setVeiculo(getVeiculoCodigo(l->getCodVeiculo()));
                    locacoes.push_back(l);
                }
            }
            fsl.close();
            cout << locacoes.size() << " LOCAÇÕES LIDAS" << endl;
        }
        else
            cout << "⚠ Não foi possível ler os Dados|VERIFIQUE O CAMINHO DO ARQUIVO" << endl;
    }
 
    void consultaLocacao()
    {
        int escolhaMenu;
        string clienteEscolha;
        string modeloEscolha;
        string modeloEscolhaMaiusculo;
        string clienteEscolhaMaiusculo;
        while (escolhaMenu != 3)
        {
            system("cls");
            cout << "----------Consulta Locação----------" << endl;
            cout << "(1) Consulta Por Cliente" << endl;
            cout << "(2) Consulta Por Modelo" << endl;
            cout << "(3) Sair" << endl;
            cout << "-------------------------------------" << endl;
            cout << "Digite uma opção: " << endl;
 
            cin >> escolhaMenu;
 
            switch (escolhaMenu)
            {
            case 1:
            {
                system("cls");
                cout << "Digite o Cliente: " << endl;
                cin >> clienteEscolha;
                system("cls");
                clienteEscolhaMaiusculo = toupper(clienteEscolha[0]);
                for (int i = 1; i < clienteEscolha.length(); i++)
                {
                    clienteEscolhaMaiusculo += clienteEscolha[i];
                }
                vector<Locacao *>::iterator it;
                for (it = locacoes.begin(); it != locacoes.end(); it++)
                {
                    if ((*it)->getCliente() == clienteEscolhaMaiusculo)
                    {
                        (*it)->imprimeDados();
                        cout << "\t" << endl;
                    }
                }
                system("pause");
                system("cls");
            }
            break;
            case 2:
            {
                system("cls");
                cout << "\nDigite o Modelo: " << endl;
                cin >> modeloEscolha;
                system("cls");
                modeloEscolhaMaiusculo = toupper(modeloEscolha[0]);
                for (int i = 1; i < modeloEscolha.length(); i++)
                {
                    modeloEscolhaMaiusculo += modeloEscolha[i];
                }
                vector<Locacao *>::iterator it;
                for (it = locacoes.begin(); it != locacoes.end(); it++)
                {
                    if ((*it)->getVeiculo()->getModelo() == modeloEscolhaMaiusculo)
                    {
                        (*it)->imprimeDados();
                        cout << "\t" << endl;
                    }
                }
                system("pause");
                system("cls");
            }
            break;
                break;
            }
        }
    }
    void realizaDevolucao()
    {
        int diariaSub;
        int diasReserva;
        int codigoVeiculoDev;
        int diariasNaoUtilizadas;
        int diariasReais;
        int escolhaMenu;
        int kmPercorridoOD;
        int kmRodadoSaveOD;
        int kmRodadoOD;
        int kmRodado;
        int getQtdDiarias5;
        int diariasAcrescentadas;
        int kmRodadoOD5;
        float valorDiaria2;
        float diariaDescontoFinal;
        float valorDiaria;
        float diariasMulti;
        float valorFinal1;
        float diariasDesconto;
        float totalAPagar1;
        float totalAPagar2;
        float getValorKmRodado1;
        float diariaMultiplicadaAC;
        float diariaTrinta;
        float diariaTrintaDiv;
        float diariasReais2;
        float valorFinal2;
        float kmRodadoCalcula;
        float totalAPagar2div;
        float totalAPagar2Soma;
        float getValorKmRodado2;
        float ValorTotalKm1;
        float valorDiaria5;
        float getValorKmRodado5;
        float kmRodadoValor1;
        float valorDiariaMult;
        float somaValorTotal;
        float valorTaxado;
        float valorTotalTaxado;
        string clienteEscolhaMaiusculo;
        string cidadeDevolucao;
        string nomeCliente;
        string cidadeOrigem1;
        string cidadeOrigem2;
        string cidadeOrigem;
        string cidadeDevo;
        string cidadeOrigem5;
 
        fflush(stdin);
        cout << "Informe Seu Nome: " << endl;
        getline(cin, nomeCliente);
 
        clienteEscolhaMaiusculo = toupper(nomeCliente[0]);
        for (int i = 1; i < nomeCliente.length(); i++)
        {
            clienteEscolhaMaiusculo += nomeCliente[i];
        }
        cout << "Informe a cidade de Devolução: " << endl;
        getline(cin, cidadeDevo);
 
        cidadeDevolucao = toupper(cidadeDevo[0]);
        for (int i = 1; i < cidadeDevo.length(); i++)
        {
            cidadeDevolucao += cidadeDevo[i];
        }
 
        vector<Locacao *>::iterator it;
        for (it = locacoes.begin(); it != locacoes.end(); it++)
        {
            if ((*it)->getCliente() == clienteEscolhaMaiusculo)
            {
                cidadeOrigem1 = (*it)->getOrigem();
                diasReserva = (*it)->getqtdDiasReserva();
                codigoVeiculoDev = (*it)->getCodVeiculo();
                cout << "Dias reservados: " << (*it)->getqtdDiasReserva();
                cout << "\n"
                     << endl;
                cout << "(1) Para Informar Quantidade De Dias Correta || (2) Para confirmar" << endl;
                cout << "Escolha a opção: " << endl;
                cin >> escolhaMenu;
                if (escolhaMenu == 1)
                {
                    cout << "Digite a Quantidade De Diarias Utilizadas: " << endl;
                    cin >> diariasReais;
                    if (diariasReais <= (*it)->getqtdDiasReserva())
                    {
                        vector<Veiculo *>::iterator ab;
                        for (ab = veiculos.begin(); ab != veiculos.end(); ab++)
                        {
                            if ((*ab)->getCodigo() == codigoVeiculoDev)
                            {
                                valorDiaria = (*ab)->getValorDiaria();
                                getValorKmRodado2 = (*ab)->getValorKmRodado();
                            }
                        }
                        diariasNaoUtilizadas = diasReserva - diariasReais;
                        diariasDesconto = valorDiaria / 2;
                        diariaDescontoFinal = diariasDesconto * diariasNaoUtilizadas;
 
                        diariaSub = diasReserva - diariasNaoUtilizadas;
                        diariasMulti = diariaSub * valorDiaria;
 
                        valorFinal1 = diariaDescontoFinal + diariasMulti;
 
                        cout << "\nValor Do Desconto: " << diariaDescontoFinal;
                        cout << "\nValor Final das Diarias: " << valorFinal1;
 
                        cout << "\ninforme os KM: " << endl;
                        cin >> kmPercorridoOD;
 
                        ValorTotalKm1 = kmPercorridoOD * getValorKmRodado2;
 
                        cout << "\nValor dos KM rodados: R$  " << ValorTotalKm1;
                        float valorFinal3;
                        float totalAPagar3soma;
 
                        valorFinal3 = ValorTotalKm1 + valorFinal1;
 
                        totalAPagar2 = valorFinal3 * 15;
                        totalAPagar2div = totalAPagar2 / 100;
 
                        totalAPagar3soma = totalAPagar2div + valorFinal3;
 
                        vector<Locacao *>::iterator ts;
                        for (ts = locacoes.begin(); ts != locacoes.end(); ts++)
                        {
 
                            if ((*ts)->getCliente() == clienteEscolhaMaiusculo)
                            {
 
                                cidadeOrigem2 = (*ts)->getOrigem();
                            }
                        }
                        if (cidadeOrigem2 == cidadeDevolucao)
                        {
                            cout << "\nValor Total A Pagar: R$ " << valorFinal3;
                        }
                        else
                        {
                            cout << "\nValor total A Pagar: R$" << totalAPagar3soma;
                        }
 
                        vector<Veiculo *>::iterator vc;
                        for (vc = veiculos.begin(); vc != veiculos.end(); vc++)
                        {
                            if ((*vc)->getCodigo() == codigoVeiculoDev)
                            {
                                kmRodadoSaveOD = (*vc)->getOdometro();
                                kmRodadoOD = kmRodadoSaveOD + kmPercorridoOD;
                                (*vc)->setOdometro(kmRodadoOD);
                                (*vc)->setCidade(cidadeDevolucao);
                                (*vc)->setDisponivel('S');
                                (*it)->setKmRodado(kmPercorridoOD);
                                (*it)->setDestino(cidadeDevolucao);
                                (*it)->setqtDiasRealizado(diariasReais);
                            }
                        }
                    }
                    else
                    {
                        vector<Veiculo *>::iterator ac;
                        for (ac = veiculos.begin(); ac != veiculos.end(); ac++)
                        {
                            if ((*ac)->getCodigo() == codigoVeiculoDev)
                            {
                                valorDiaria2 = (*ac)->getValorDiaria();
                                getValorKmRodado1 = (*ac)->getValorKmRodado();
                            }
                        }
 
                        diariasAcrescentadas = diariasReais - diasReserva;
 
                        diariaTrinta = valorDiaria2 * 30;
                        diariaTrintaDiv = diariaTrinta / 100;
 
                        diariaMultiplicadaAC = diariaTrintaDiv * diariasAcrescentadas;
                        diariasReais2 = diasReserva * valorDiaria2;
 
                        valorFinal2 = diariasReais2 + diariaMultiplicadaAC;
 
                        cout << "\nDias de acrescimo:  " << diariasAcrescentadas;
                        cout << "\nValor Diarias Previstas: R$ " << diariasReais2;
                        cout << "\nValor do acrescimo: R$ " << diariaMultiplicadaAC;
                        cout << "\nValor Final das Diarias: R$  " << valorFinal2;
 
                        cout << "\ninforme a Kilometragem Percorrida: " << endl;
                        cin >> kmPercorridoOD;
 
                        kmRodadoCalcula = kmPercorridoOD * getValorKmRodado1;
                        totalAPagar1 = kmRodadoCalcula + valorFinal2;
 
                        totalAPagar2 = totalAPagar1 * 15;
                        totalAPagar2div = totalAPagar2 / 100;
 
                        totalAPagar2Soma = totalAPagar2div + totalAPagar1;
 
                        cout << "\nValor dos KM rodados: R$  " << kmRodadoCalcula;
 
                        vector<Locacao *>::iterator ts;
                        for (ts = locacoes.begin(); ts != locacoes.end(); ts++)
                        {
 
                            if ((*ts)->getCliente() == clienteEscolhaMaiusculo)
                            {
 
                                cidadeOrigem2 = (*ts)->getOrigem();
                            }
                        }
                        if (cidadeOrigem2 == cidadeDevolucao)
                        {
                            cout << "\nValor Total A Pagar: R$ " << totalAPagar1;
                        }
                        else
                        {
                            cout << "\nValor total A Pagar: R$" << totalAPagar2Soma;
                        }
 
                        vector<Veiculo *>::iterator vc;
                        for (vc = veiculos.begin(); vc != veiculos.end(); vc++)
                        {
                            if ((*vc)->getCodigo() == codigoVeiculoDev)
                            {
                                kmRodadoSaveOD = (*vc)->getOdometro();
                                kmRodadoOD = kmRodadoSaveOD + kmPercorridoOD;
                                (*vc)->setOdometro(kmRodadoOD);
                                (*vc)->setCidade(cidadeDevolucao);
                                (*vc)->setDisponivel('S');
                                (*it)->setKmRodado(kmPercorridoOD);
                                (*it)->setDestino(cidadeDevolucao);
                                (*it)->setqtDiasRealizado(diariasReais);
                            }
                        }
                    }
                }
                else
                {
 
 
                    vector<Locacao *>::iterator loc;
                    for (loc = locacoes.begin(); loc != locacoes.end(); loc++)
                    {
                        if ((*loc)->getCliente() == clienteEscolhaMaiusculo)
                        {
                            getQtdDiarias5 = (*loc)->getqtdDiasReserva();
                            cidadeOrigem5 = (*loc)->getOrigem();
                        }
                    }
 
                    cout << "Digite a Kilometragem Percorrida: " << endl;
                    cin >> kmRodado;
 
                    vector<Veiculo *>::iterator ai;
                    for (ai = veiculos.begin(); ai != veiculos.end(); ai++)
                    {
                        if ((*ai)->getCodigo() == codigoVeiculoDev)
                        {
                            valorDiaria5 = (*ai)->getValorDiaria();
                            getValorKmRodado5 = (*ai)->getValorKmRodado();
                        }
                    }
                    kmRodadoValor1 = kmRodado * getValorKmRodado5;
 
                    valorDiariaMult = valorDiaria5 * getQtdDiarias5;
 
                    somaValorTotal = kmRodadoValor1 + valorDiariaMult;
 
                    valorTaxado = (somaValorTotal * 15) / 100;
 
                    valorTotalTaxado = valorTaxado + somaValorTotal;
 
                    if (cidadeOrigem5 == cidadeDevolucao)
                    {
                        cout << "\nValor Total A Pagar: R$ " << somaValorTotal;
                    }
                    else
                    {
                        cout << "\nValor total A Pagar: R$" << valorTotalTaxado;
                    }
 
                    vector<Veiculo *>::iterator vc;
                    for (vc = veiculos.begin(); vc != veiculos.end(); vc++)
                    {
                        if ((*vc)->getCodigo() == codigoVeiculoDev)
                        {
                            kmRodadoSaveOD = (*vc)->getOdometro();
                            kmRodadoOD5 = kmRodadoSaveOD + kmRodado;
                            (*vc)->setOdometro(kmRodadoOD5);
                            (*vc)->setCidade(cidadeDevolucao);
                            (*vc)->setDisponivel('S');
                        }
                    }
                    vector<Locacao *>::iterator ts;
                    for (ts = locacoes.begin(); ts != locacoes.end(); ts++)
                    {
                        if ((*ts)->getCliente() == clienteEscolhaMaiusculo)
                        {
                            (*it)->setKmRodado(kmRodado);
                            (*it)->setDestino(cidadeDevolucao);
                            (*it)->setqtDiasRealizado(getQtdDiarias5);
                        }
                    }
                }
                cout << "\nVeiculo liberado com sucesso!\n"
                     << endl;
            }
        }
        system("pause");
    }
    void resumoDados()
    {
        int diasReserva = 0;
        int diasReservaSoma = 0;
        int diasReservaPrint = 0;
        int diasRealizados = 0;
        int diasRealizadosSoma = 0;
        int diasRealizadosPrint = 0;
        int kmRodado = 0;
        int kmRodadoSoma = 0;
        int kmRodadoPrint = 0; 
        int diasReserva1 = 0;
        int diasRealizados1 = 0;
        int getKmRodado = 0;
        int codVeiculo;
        float acumulaKM;
        float taxa30Per;
        float taxa30PerMultipl;
        float taxa30PerDiv;
        float somaTudo;
        float valorTotalLocacoes;
        float totalKmRodado;
        float getPrecoKmRodado = 0;
        float getValorDia = 0;
        float diasReservaSoma1 = 0;
        float diasReservaPrint1 = 0;
        float testeSoma;
        float diaria30;
        float diaria30Print;
        string cidadeOrigem;
        string cidadeDestino;
 
 
        vector<Locacao *>::iterator rs;
        for (rs = locacoes.begin(); rs != locacoes.end(); rs++)
        {
            diasReserva = (*rs)->getqtdDiasReserva();
            diasReservaSoma += diasReserva;
            diasReservaPrint = diasReservaSoma;
 
            diasRealizados = (*rs)->getqtDiasRealizado();
            diasRealizadosSoma += diasRealizados;
            diasRealizadosPrint = diasRealizadosSoma;
            if ((*rs)->getqtDiasRealizado() > 0)
            {
                kmRodado = (*rs)->getkmRodado();
                kmRodadoSoma += kmRodado;
                kmRodadoPrint = kmRodadoSoma;
            }
        }
        cout << "\n-------------------------Resumo----------------------------" << endl;
        cout << "Total De KM's Rodados: " << kmRodadoPrint;
        cout << "\nTotal De Dias Reservados: " << diasReservaPrint;
        cout << "\nTotal De Dias Realizados: " << diasRealizadosPrint;
 
        int diasExtras = diasReservaPrint - diasRealizadosPrint;
 
        vector<Veiculo *>::iterator ns;
        for (ns = veiculos.begin(); ns != veiculos.end(); ns++)
        {
            codVeiculo = (*ns)->getCodigo();
            getPrecoKmRodado = (*ns)->getValorKmRodado();
            getValorDia = (*ns)->getValorDiaria();
 
            diaria30 = (getValorDia * 30) / 100;
            diaria30Print = diaria30 * diasExtras;
 
            vector<Locacao *>::iterator tst;
            for (tst = locacoes.begin(); tst != locacoes.end();tst++){
                if ((*tst)->getCodVeiculo() == codVeiculo )
                {
                    getKmRodado = (*tst)->getkmRodado();
                    diasReserva1 = (*tst)->getqtdDiasReserva();
                    cidadeDestino = (*tst)->getDestino();
                    cidadeOrigem = (*tst)->getOrigem();
                }
            }
            diasReservaSoma1 = diasReserva1 * getValorDia;
            diasReservaPrint1 += diasReservaSoma1;
 
            totalKmRodado = getKmRodado * getPrecoKmRodado;
            acumulaKM +=totalKmRodado;
 
            if(cidadeDestino == cidadeOrigem)
            {
               taxa30Per = totalKmRodado + diasReservaSoma;
            }else{
                taxa30Per = totalKmRodado + diasReservaSoma;
                taxa30PerMultipl = taxa30Per * 15;
                taxa30PerDiv = taxa30PerMultipl / 100;
            }
           
        } 
        somaTudo += taxa30PerDiv + taxa30Per;
        valorTotalLocacoes = diasReservaPrint1 + diaria30Print + acumulaKM + somaTudo;
        cout << "\nValor Total Das Diarias: R$ " << diasReservaPrint1;
        cout << "\nValor Total Das Diarias Extras: R$ " << diaria30Print;
        cout << "\nValor Total Dos Km Rodados: R$ " << acumulaKM;
        cout << "\nValor Total Roaming: R$ " << somaTudo;
        cout << "\nValor Total Das Locações: R$ " << valorTotalLocacoes;
        cout << "\n-----------------------------------------------------------\n" << endl;
        system("pause");
    }
    int encerrarSistema()
    {
        int escolhaMenu;
        salvaDados();
        escolhaMenu = 8;
 
        cout << endl << "---------------------------Sistema Encerrado!-----------------------" << endl;
        return escolhaMenu;
    }
};
 
int main()
{
    Locadora *loc = new Locadora();
    loc->carregaDados();
    int escolhaMenu;
    while (escolhaMenu != 7)
    {
        system("cls");
        cout << "-----------------------MENU-----------------------" << endl;
        cout << "(1) Consultar Veiculos" << endl;
        cout << "(2) Realizar Locacao" << endl;
        cout << "(3) Realizar devolução" << endl;
        cout << "(4) Consultar locações" << endl;
        cout << "(5) Resumo" << endl;
        cout << "(6) Salvar " << endl;
        cout << "(7) Sair " << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Digite uma opção: " << endl;
        cin >> escolhaMenu;
        switch (escolhaMenu)
        {
        case 1:
            loc->consultaVeiculo();
            break;
        case 2:
            loc->realizaLocacao();
            break;
        case 3:
            loc->realizaDevolucao();
            break;
        case 4:
            loc->consultaLocacao();
            break;
        case 5:
            loc->resumoDados();
            break;
        case 6:
            loc->salvaDados();
            break;
        case 7:
            loc->encerrarSistema();
            break;
        }
    }
}
 
