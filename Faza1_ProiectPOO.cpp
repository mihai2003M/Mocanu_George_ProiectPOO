//domeniuInitiale = imagine; 3 obiecte = aparat foto, drone de filmare, proiector imagine
//atribute normale, constante si statice
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class AparatFoto {
private:
	static string portIncarcare;
	static float TVA;
	static float calcTVA(float a) {
		return a * TVA;
	}
	const int id;
	int nrAparate;
	const string tipAparat;
	string model;
	char* marca;
	int autonomie;
	int zoom;
	float pret;
public:
	static float getTVA() {
		return TVA;
	}
	static void setTVA(float TvaNou) {
		TVA = TvaNou;
	}

	static void setCalcTva(float pret) {
		cout << pret * TVA;
	}


	AparatFoto(const char* marca) :id(1), tipAparat("DSLR") {
		this->model = "Canon 4000 D";
		this->autonomie = 1400;
		this->zoom = 50;
		this->pret = 1500.50;
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
	}

	AparatFoto(const char* marca, int idNou, string tipAparatNou) :id(idNou), tipAparat(tipAparatNou) {
		this->model = "Sony A7";
		this->autonomie = 2400;
		this->zoom = 200;
		this->pret = 7000;
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
	}



	AparatFoto(const char* marca, int idNou, string tipAparatNou, string modelNou, int autonomieNoua, int zoomNou, float pretNou)
		:id(idNou), tipAparat(tipAparatNou), model(modelNou), autonomie(autonomieNoua), zoom(zoomNou), pret(pretNou) {
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);

	}

	AparatFoto(const AparatFoto& p) : id(p.id), tipAparat(p.tipAparat) {
		this->model = p.model;
		this->autonomie = p.autonomie;
		this->zoom = p.zoom;
		this->pret = p.pret;
		this->marca = new char[strlen(p.marca) + 1];
		strcpy(this->marca, p.marca);

	}

	~AparatFoto() {
		if (id != NULL) {
			delete[]this->marca;
		}
	}

	void afisare() {

		cout << " Tip: " << tipAparat << "Autonomie(cadre): "
			<< this->autonomie << ", Zoom optic pana la: " << this->zoom << "x " << ", Pretul: " << pret << " lei"
			<< ", Mufa incarcare: " << portIncarcare << ", Marca: " << marca;

	}

	const int getId() {
		return id;
	}

	const string getTipAparat() {
		return tipAparat;
	}

	void setModel(string model) {
		this->model = model;
	}
	string getModel() {
		return model;
	}

	void setMarca(char* marca) {
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
	}
	char* getMarca() {
		return marca;
	}


	int getAutonomie() {
		return autonomie;
	}
	void setAutonomie(int autonomie) {
		this->autonomie = autonomie;
	}

	int getZoom() {
		return zoom;
	}
	void setZoom(int zoom) {
		this->zoom = zoom;
	}
	void setPret(float p) {
		this->pret = pret;
	}
	float getPret() {
		return pret;
	}

	friend float getPret1(AparatFoto a);
	friend string getModel1(AparatFoto b);
};

float getPret1(AparatFoto a) {
	if (a.pret < 2000) {
		cout << " Aparatul este in bugetul clientului ,";
	}
	return a.pret;
}
string getModel1(AparatFoto b) {
	if (b.model == "Canon 4000 D") {
		return b.model;
	}
	//return b.model;
}

string AparatFoto::portIncarcare = "Type C";
float AparatFoto::TVA = 0.19;


class Drona {
private:
	static int perioadaRetur;
	const int id;
	const float greutate;
	char* model;
	string rezolutieCamera;
	float autonomie;
	string conectivitate;
	float altitudineZbor;
public:
	static int getPerioadaRetur() {
		return perioadaRetur;
	}
	void setPerioadaRetur(int perioadaRetur) {
		this->perioadaRetur = perioadaRetur;
	}
	static int returnarePosibila(int posesieClient) {
		if (posesieClient < perioadaRetur)
			cout << "Se poate face returul, clientul are produsul de: ";
		else
			cout << "Nu se mai poate face returul,clientul are produsul deja de: ";
		return posesieClient;
	}
	const int getId() {
		return id;
	}
	const float getGreutate() {
		return greutate;
	}
	void setModel(char* model) {
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
	}
	char* getModel() {
		return model;
	}
	string getRezolutieCamera() {
		return rezolutieCamera;
	}
	void setRezolutieCamera(string rezluitaCamera) {
		this->rezolutieCamera = rezolutieCamera;
	}

	float getAutonomie() {
		return autonomie;
	}
	void setAutonomie() {
		this->autonomie = autonomie;
	}
	string getConectivitate() {
		return conectivitate;
	}
	void setAltitudineZbor(float altitudineZbor) {
		this->altitudineZbor = altitudineZbor;
	}
	float getAltitudineZbor() {
		return altitudineZbor;
	}


	Drona(const char* model) :id(1), greutate(650.8) {
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
		rezolutieCamera = "4k";
		autonomie = 1.3;
		conectivitate = "Wi-Fi 5G ";
		altitudineZbor = 825.5;
	}

	Drona(const char* model, int idNou, float greutateNoua, string rezolutieCameraNoua) :
		id(idNou), greutate(greutateNoua), rezolutieCamera(rezolutieCameraNoua) {
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
		autonomie = 0.3;
		conectivitate = "Wi-Fi 4 ";
		altitudineZbor = 600;
	}

	Drona(const char* model, int idNou, float greutateNoua, string rezolutieCameraNoua, float autonomieNoua) : id(idNou),
		greutate(greutateNoua), rezolutieCamera(rezolutieCameraNoua), autonomie(autonomieNoua) {
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
		conectivitate = "Wi-Fi 4 ";
		altitudineZbor = 450;
	}
	Drona(const Drona& p) :id(p.id), greutate(p.greutate) {
		this->model = new char[strlen(p.model) + 1];
		strcpy(this->model, p.model);
		this->rezolutieCamera = p.rezolutieCamera;
		this->autonomie = p.autonomie;
		this->conectivitate = p.autonomie;
		this->altitudineZbor = p.altitudineZbor;
	}

	~Drona() {
		if (altitudineZbor != NULL) {
			delete[]this->model;

		}
	}

	void afisare() {
		cout << " Modelul: " << model << ", Are rezolutia: " << rezolutieCamera << ", O autonomie de: "
			<< autonomie << " de h" << ", Conectivitate: " << conectivitate << ", Altitudine maxima zbor: "
			<< altitudineZbor << ", O greutate de: " << greutate << endl;
	}
};

int Drona::perioadaRetur = 30;



class Proiector {
private:
	static string mufaConectare;
	static string sePoateConecta(string mufaClient) {
		if (mufaClient == mufaConectare)
			cout << " Se poate conecta la proiecor: ";
		else
			cout << " Are nevoie de adaptor: ";
		return mufaConectare;

	};
	const int id;
	const string rezolutie;
	char* model;
	char* marca;
	int contrast;
	int nrLumeni;
	float pret;
public:
	static string getMufaConectare() {
		return mufaConectare;
	}
	void setMufaConectare(string mufaConectare) {
		this->mufaConectare = mufaConectare;
	}
	string getSePoateConecta(string mufaClient) {
		if (mufaClient == mufaConectare)
			cout << "Se poate conecta la proiecor: ";
		else
			cout << "Are nevoie de adaptor: ";
		return mufaConectare;
	}

	const int getId() {
		return id;
	}
	const string getRezolutie() {
		return rezolutie;
	}
	void setModel(char* model) {
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
	}
	char* getModel() {
		return model;
	}
	void setMarca(char* marca) {
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
	}
	char* getMarca() {
		return marca;
	}
	int getContrast() {
		return contrast;
	}
	void setContrast(int contrast) {
		this->contrast = contrast;
	}
	int getNrLumeni() {
		return nrLumeni;
	}
	void SetNrLumeni(int nrLumeni) {
		this->nrLumeni = nrLumeni;
	}
	float getPret() {
		return pret;
	}
	void setPret(float pret) {
		this->pret = pret;
	}

	Proiector(const char* model, const char* marca) :id(1), rezolutie("4K") {
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
		contrast = 1000;
		nrLumeni = 13000;
		pret = 1888.9;
	}

	Proiector(const char* model, const char* marca, int idNou, string rezolutieNoua, float pretNou)
		: id(idNou), rezolutie(rezolutieNoua), pret(pretNou)
	{
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
		contrast = 4000;
		nrLumeni = 8000;
	}

	Proiector(const char* model, const char* marca, int idNou, string rezolutieNoua, int contrastNou, int nrLumeniNou, float pretNou) :id(idNou),
		rezolutie(rezolutieNoua), contrast(contrastNou), nrLumeni(nrLumeniNou), pret(pretNou) {
		this->model = new char[strlen(model) + 1];
		strcpy(this->model, model);
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
	}
	Proiector(const Proiector& p) :id(p.id), rezolutie(p.rezolutie) {
		this->model = new char[strlen(p.model) + 1];
		strcpy(this->model, p.model);
		this->marca = new char[strlen(p.marca) + 1];
		strcpy(this->marca, p.marca);
		this->contrast = p.contrast;
		this->nrLumeni = p.nrLumeni;
		this->pret = p.pret;

	}


	~Proiector() {
		if (contrast != NULL) {
			delete[]this->marca;
		}
	}

	void afisare() {
		cout << " Model: " << model << ", Marca: " << marca << " ,Contrast: " << contrast << " la 1" << ", Rezolutie: "
			<< rezolutie << " , Nr Lumeni: " << nrLumeni << ", Pret: " << pret << endl;
	}
	friend float discount(Proiector a);
	friend float TVA(Proiector b);
	friend string incadreareBuget(Proiector b, int salariu);
};

float discount(Proiector a) {
	float valoareFinala = 0;
	valoareFinala = 0.8 * a.getPret();
	return valoareFinala;
}

float TVA(Proiector b) {
	float valoareFinala = 0;
	valoareFinala = 0.19 * b.getPret();
	return valoareFinala;
}

string incadrareBuget(Proiector b, int salariu) {
	string decizie;
	if (salariu >= 4 * b.getPret()) {
		decizie = "Si-l permite.";
	}
	else {
		decizie = "Nu si-l permite";
	}
	return decizie;
}

string Proiector::mufaConectare = "HDMI";

void main() {

	//clasa 1 Aparat Foto
	AparatFoto aparat1("Canon");

	cout << "APARAT" << endl;
	cout << "\nId: " << aparat1.getId() << "\nTip: " << aparat1.getTipAparat() << "\nModelul: " << aparat1.getModel() << "\nMarca: "
		<< aparat1.getMarca() << "\nAutonomie: " << aparat1.getAutonomie() << " de cadre " << "\nZoom :" << aparat1.getZoom() << "\nUn pret de: " << aparat1.getPret()
		<< "\nTva calc: ";
	aparat1.setCalcTva(1500.50);
	cout << "\nModelul aparatului este? " << getModel1(aparat1);
	cout << "\n------------------------------------------------------------------------------------";;

	AparatFoto aparat2("Sony", 2, "DSLR");

	cout << endl << getPret1(aparat2);
	cout << "\nId: " << aparat2.getId() << "\nTip: " << aparat2.getTipAparat() << "\nModelul: " << aparat2.getModel() << "\nMarca: "
		<< aparat2.getMarca() << "\nAutonomie: " << aparat2.getAutonomie() << " de cadre " << "\nZoom :" << aparat2.getZoom() << "\nUn pret de: " << aparat2.getPret();
	cout << "\n------------------------------------------------------------------------------------";


	AparatFoto aparat3("Nikon", 3, "DSLR", "Nikon 12A", 4000, 175, 7000);


	cout << "\nId: " << aparat3.getId() << "\nTip: " << aparat3.getTipAparat() << "\nModelul: " << aparat3.getModel() << "\nMarca: "
		<< aparat3.getMarca() << "\nAutonomie: " << aparat3.getAutonomie() << " de cadre " << "\nZoom :" << aparat3.getZoom() << "\nUn pret de: " << aparat3.getPret();
	cout << "\n------------------------------------------------------------------------------------";

	AparatFoto aparat4(aparat1);
	cout << "\nId: " << aparat4.getId() << "\nTip: " << aparat4.getTipAparat() << "\nModelul: " << aparat4.getModel() << "\nMarca: "
		<< aparat4.getMarca() << "\nAutonomie: " << aparat4.getAutonomie() << " de cadre " << "\nZoom :" << aparat4.getZoom() << "\nUn pret de: " << aparat4.getPret();
	cout << "\n------------------------------------------------------------------------------------" << endl;


	//clasa 2 Drone de Filmat
	cout << "DRONA" << endl;
	Drona drona1("SG906 PRO Max");
	drona1.setPerioadaRetur(29);

	cout << "\nId: " << drona1.getId() << "\nGreutate: " << drona1.getGreutate() << "\nModel: " << drona1.getModel() << "\nRezolutie camera: "
		<< drona1.getRezolutieCamera() << "\nAutonomie: " << drona1.getAutonomie() << "\nConectivitate: " << drona1.getConectivitate() << "\nAltitudine zbor: " << drona1.getAltitudineZbor();
	cout << "\n" << Drona::returnarePosibila(21) << " zile";
	cout << "\n------------------------------------------------------------------------------------";

	Drona drona2("FR 11", 2, 657.5, "4k");
	cout << "\nId: " << drona2.getId() << "\nGreutate: " << drona2.getGreutate() << "\nModel: " << drona2.getModel() << "\nRezolutie camera: "
		<< drona2.getRezolutieCamera() << "\nAutonomie: " << drona2.getAutonomie() << "\nConectivitate: " << drona2.getConectivitate() << "\nAltitudine zbor: " << drona2.getAltitudineZbor();
	cout << "\n------------------------------------------------------------------------------------";


	Drona drona3("HouDeOS", 3, 500.3, "2k", 0.24);
	cout << "\nId: " << drona3.getId() << "\nGreutate: " << drona3.getGreutate() << "\nModel: " << drona3.getModel() << "\nRezolutie camera: "
		<< drona3.getRezolutieCamera() << "\nAutonomie: " << drona3.getAutonomie() << "\nConectivitate: " << drona3.getConectivitate() << "\nAltitudine zbor: " << drona3.getAltitudineZbor();
	cout << "\n------------------------------------------------------------------------------------";

	Drona drona4(drona1);
	cout << "\nId: " << drona4.getId() << "\nGreutate: " << drona4.getGreutate() << "\nModel: " << drona4.getModel() << "\nRezolutie camera: "
		<< drona4.getRezolutieCamera() << "\nAutonomie: " << drona4.getAutonomie() << "\nConectivitate: " << drona4.getConectivitate() << "\nAltitudine zbor: " << drona4.getAltitudineZbor();
	cout << "\n------------------------------------------------------------------------------------" << endl;


	//clasa 3 videoproiectoare
	cout << "PROIECTOR" << endl;
	Proiector proiector1("SW 10", "SUREWHELL");
	proiector1.setMufaConectare("VGA");
	cout << proiector1.getSePoateConecta("HDMI");
	cout << "\nPret aplicare discount: " << discount(proiector1);
	cout << "\nId: " << proiector1.getId() << "\nRezolutie: " << proiector1.getRezolutie() << "\nModel: " << proiector1.getModel() << "\nMarca: " << proiector1.getModel() << "\nContrast:"
		<< proiector1.getContrast() << "\nNr Lumeni: " << proiector1.getNrLumeni() << "\nPret: " << proiector1.getPret();;
	cout << "\n------------------------------------------------------------------------------------" << endl;

	Proiector proiector2("YG430 WiFi", "Loosafe", 2, "Full-HD", 800.5);
	//int salariu = 5000;
	//string itiPermiti = incadreareBuget(proiector2, salariu);
	cout << "TVA Produs: " << TVA(proiector2);
	cout << "\nId: " << proiector2.getId() << "\nRezolutie: " << proiector2.getRezolutie() << "\nModel: " << proiector2.getModel() << "\nMarca: " << proiector2.getModel() << "\nContrast:"
		<< proiector2.getContrast() << "\nNr Lumeni: " << proiector2.getNrLumeni() << "\nPret: " << proiector2.getPret();
	//cout << "\nSe incadreaza in buget? " << itiPermiti;
	cout << "\n------------------------------------------------------------------------------------" << endl;

	Proiector proiector3("WowStep M", "Wowstep", 3, "HD", 2000, 7000, 995.7);
	cout << "\nId: " << proiector3.getId() << "\nRezolutie: " << proiector3.getRezolutie() << "\nModel: " << proiector3.getModel() << "\nMarca: " << proiector3.getModel() << "\nContrast:"
		<< proiector3.getContrast() << "\nNr Lumeni: " << proiector3.getNrLumeni() << "\nPret: " << proiector3.getPret();
	cout << "\n------------------------------------------------------------------------------------" << endl;

	Proiector proiector4(proiector1);
	cout << "\nId: " << proiector4.getId() << "\nRezolutie: " << proiector4.getRezolutie() << "\nModel: " << proiector4.getModel() << "\nMarca: " << proiector4.getModel() << "\nContrast:"
		<< proiector4.getContrast() << "\nNr Lumeni: " << proiector4.getNrLumeni() << "\nPret: " << proiector4.getPret();
	cout << "\n------------------------------------------------------------------------------------" << endl;
}


