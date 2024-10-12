#include<iostream>
#include<stdlib.h>

//prototypage des fonctions à utiliser
unsigned int factoriel(unsigned int n);
float puissance(float a, float b);
float cosinus(float c);
float sinus(float c);
float tangente(float c);

//déclaration des fonctions
unsigned int factoriel(unsigned int n){
	unsigned int i,fact = 1;
	for(i=1; i<=n; i++){
		fact = fact * i;
	}
	return fact;
}

float puissance(float a, float b){
	float exp = 1.0;
	int i;
	for(i=1; i<=b; i++){
		exp = exp * a;
	}
	return exp;
}

float cosinus(float c){
    float cos = 0.0;
    if(c == 90){
        cos = 0;
    }else if(c == 180){
        cos = -1;
    }else if(c == 270){
        cos = 1;
    }else if(c < 90){
        float rad = (c * 3.1415926535897932384626433832795)/180;
        int i;
        for(i=0; i<=16; i++){
            cos = cos+(puissance(-1,i) * puissance(rad,2*i))/factoriel(2*i);
        }
    }else if(c > 180){
        float nouv = c-180;
        float rad = (nouv * 3.1415926535897932384626433832795)/180;
        int i;
        for(i=0; i<=16; i++){
            cos = cos+(puissance(-1,i) * puissance(rad,2*i))/factoriel(2*i);
        }
        cos = -1 * cos;
    }else if(c > 90 && c < 180){
        float nouv = 180-c;
        float rad = (nouv * 3.1415926535897932384626433832795)/180;
        int i;
        for(i=0; i<=16; i++){
            cos = cos+(puissance(-1,i) * puissance(rad,2*i))/factoriel(2*i);
        }
        cos = -1 * cos;
    }
	return cos;
}

float sinus(float c){
     float sin = 0.0;
    if(c == 90){
        sin = 1;
    }else if(c == 180){
        sin = 0;
    }else if(c == 270){
        sin = -1;
    }
    if(c > 90 && c < 180){
        float nouv = 180-c;
        float rad = (nouv * 3.1415926535897932384626433832795)/180;
        int i;
        for(i=0; i<=16; i++){
            sin = sin+(puissance(-1,i) * puissance(rad,(2*i)+1))/factoriel((2*i)+1);
        }
        }else if(c < 90){
            float rad = (c * 3.1415926535897932384626433832795)/180;
            int i;
            for(i=0; i<=16; i++){
                sin = sin+(puissance(-1,i) * puissance(rad,(2*i)+1))/factoriel((2*i)+1);
            }
        }else if(c > 180 && c != 270){
            float nouv = c-180;
            float rad = (nouv * 3.1415926535897932384626433832795)/180;
            int i;
            for(i=0; i<=16; i++){
                sin = sin+(puissance(-1,i) * puissance(rad,(2*i)+1))/factoriel((2*i)+1);
            }
        sin = -1 * sin;
    }
	return sin;
}

float tangente(float c){
    float tan = 0.0;
    float cos = 0.0;
	float sin = 0.0;
    if(c == 90){
        sin = 1;
        cos = 0;
    }else if(c == 180){
        sin = 0;
        cos = -1;
        tan = 0;
    }else if(c == 270){
        sin = -1;
        cos = 1;
    }
    if(c > 90 && c < 180){
        float nouv = 180-c;
        float rad = (nouv * 3.1415926535897932384626433832795)/180;
        int i;
        for(i=0; i<=16; i++){
            sin = sin+(puissance(-1,i) * puissance(rad,(2*i)+1))/factoriel((2*i)+1);
             cos = cos+(puissance(-1,i) * puissance(rad,2*i))/factoriel(2*i);
        }
        cos = -1 * cos;
        }else if(c < 90){
            float rad = (c * 3.1415926535897932384626433832795)/180;
            int i;
            for(i=0; i<=16; i++){
                sin = sin+(puissance(-1,i) * puissance(rad,(2*i)+1))/factoriel((2*i)+1);
                 cos = cos+(puissance(-1,i) * puissance(rad,2*i))/factoriel(2*i);
            }
        }else if(c > 180 && c != 270){
            float nouv = c-180;
            float rad = (nouv * 3.1415926535897932384626433832795)/180;
            int i;
            for(i=0; i<=16; i++){
                sin = sin+(puissance(-1,i) * puissance(rad,(2*i)+1))/factoriel((2*i)+1);
                 cos = cos+(puissance(-1,i) * puissance(rad,2*i))/factoriel(2*i);
            }
        cos = -1 * cos;
        sin = -1 * sin;
    }
    tan = sin/cos;
	return tan;
}

//declaration des variables globales
float angle = 0.0;
float co = 0.0, si = 0.0, ta = 0.0;
int i = 0;

//fonction principale
int main(int argc, char** argv){
	//interface d'interaction avec l'utilisateur
	std::cout<<"                            Choisissez une option"<<std::endl<<std::endl;
	std::cout<<"------------------------------------------------------------------------------"<<std::endl<<std::endl;
	std::cout<<"                         [1] Calculer le cosinus d'un angle"<<std::endl<<std::endl;
	std::cout<<"                         [2] Calculer le sinus d'un angle"<<std::endl<<std::endl;
	std::cout<<"                         [3] Calculer la tangente d'un angle"<<std::endl<<std::endl;
	std::cout<<"--------------------------------------------------------------------------------"<<std::endl<<std::endl;
	unsigned int choix = 0;
	std::cout<<"Faites le choix :";
	std::cin>>choix;

	//parametrage du menu et de chaque option
	switch(choix){

		//parametrage pour le cosinus
		case 1:
            system("cls");
			std::cout<<"Entrez la mesure de l'angle :";
			std::cin>>angle;
			co = cosinus(angle);
			std::cout<<"le cosinus est : "<<co;
		break;

		//parametrage pour le sinus
		case 2:
            system("cls");
			std::cout<<"Entrez la mesure de l'angle :";
			std::cin>>angle;
			si = sinus(angle);
			std::cout<<"le sinus est : "<<si;
		break;

		//parametrage pour la tangente
		case 3:
			system("cls");
			std::cout<<"Entrez la mesure de l'angle :";
			std::cin>>angle;
			ta = tangente(angle);
			std::cout<<"la tangente est : "<<ta;
		break;
	}
}
