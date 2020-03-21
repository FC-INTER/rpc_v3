/* Subscription management */

struct abonnement {
    int id_abo;
    char type_abo[30];
    int prix_abo;
    int credit_abo;
};

struct list_abonnement{
    struct abonnement abonnements[15];
    int nb_different_abonnement;
};

/*-------------------------------------------*/
/* collection management */

struct collection {
    int id_collection;
    char nom_collection[50];
};

struct list_collection {
    struct collection collection[15];
    int nb_different_collection;
};
/*-------------------------------------------*/
/* Brand management */

struct brand{
    int id_brand;
    char brand_name[32];
    char description[3000];
};

struct list_brand{
    struct brand brands[15];
    int nb_different_brand;
};

/*-------------------------------------------*/
/* Article management */

enum point_livraison{
    Paris_Neuilly_Boulogne = 1,
    Rest_of_France = 2,
    Belgium = 3,
    UK = 4
};

struct article {
    int id_article;
    char nom[32];
    int taille[20];
    enum point_livraison pt_livraison;
    int prix_location;
    struct collection collection_reference;
    struct brand brand_reference;
    int credit;
    int stock;
};

struct article_list{
    struct article article[15];
    int nb_different_article;
};
/*-------------------------------------------*/
/* account management */
enum connu_panoply {
	Par_une_amie = 1,
	Une_recherche_en_ligne = 2,
	Un_article_de_presse = 3,
	Aux_galerie_lafayette = 4,
	Sur_les_reseaux_sociaux = 5,
	Autre = 6
};

struct mail {
	char email[128] ;
};

struct mot_de_passe{
	char mdp[32] ;
};

struct date {
	int jour;
	int mois;
	int annee;
};

struct identifiants{
	struct mail email;
	struct mot_de_passe mdp;
};

struct compte {
    int id_compte;
	struct mail email;
	struct mot_de_passe mdp;
	char nom[32];
	char prenom[32];
	struct date date_de_naissance;
	int telephone;
	char profession[64];
	char pays[32];
    int nb_credit;
	enum connu_panoply connaissance;
    struct abonnement abonnement_suivi;
    struct date date_abonnement;
};

struct list_account{
    struct compte cmpt[15];
    int nbCompte;
};

/*-------------------------------------------*/

/* Order management */
struct cart{
    int id_cart;
    struct article list_article[15];
    int nbArticle;
    int rent_price_credit;
    int rent_price_euros;
    enum point_livraison pt_livraison;
    struct date date_livraison;
    struct date date_rendu; 
};

struct historiqueCommande {
    struct cart listCommande[15];
    int nbCommande;
};
/*-------------------------------------------*/
/*database*/
struct panoply {
    struct list_account comptes;
    struct list_collection collections;
    struct article_list articles;
    struct list_abonnement abonnements;
    struct list_brand marques;
    struct historiqueCommande commandes;
};

/*-------------------------------------------*/
/*Fonctions*/

program SERVICE_PANOPLY{
    version SERVICE_VERSION_1{
        void INIT() = 1;
        compte CREATE_ACCOUNT(compte) = 2;
        int LOG_IN(identifiants) = 3;
        list_abonnement LIST_TYPE_ABO() = 4;
        compte AFFECTER_ABO_CLIENT(compte) = 5;
        list_collection LIST_ALL_COLLECTION() = 6;
        article_list LIST_ALL_COLLECTION_CLOTHES(collection) = 7;
        cart ADD_TO_CART(cart)= 8; 
        
    } = 1;
} = 0x20646464;
