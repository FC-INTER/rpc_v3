/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _PANOPLY_H_RPCGEN
#define _PANOPLY_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct abonnement {
	int id_abo;
	char type_abo[30];
	int prix_abo;
	int credit_abo;
};
typedef struct abonnement abonnement;

struct list_abonnement {
	struct abonnement abonnements[5];
	int nb_different_abonnement;
};
typedef struct list_abonnement list_abonnement;

struct collection {
	int id_collection;
	char nom_collection[20];
};
typedef struct collection collection;

struct list_collection {
	struct collection collection[5];
	int nb_different_collection;
};
typedef struct list_collection list_collection;

struct brand {
	int id_brand;
	char brand_name[20];
	char description[20];
};
typedef struct brand brand;

struct list_brand {
	struct brand brands[5];
	int nb_different_brand;
};
typedef struct list_brand list_brand;

enum point_livraison {
	Paris_Neuilly_Boulogne = 1,
	Rest_of_France = 2,
	Belgium = 3,
	UK = 4,
};
typedef enum point_livraison point_livraison;

struct article {
	int id_article;
	char nom[32];
	int taille[5];
	enum point_livraison pt_livraison;
	int prix_location;
	struct collection collection_reference;
	struct brand brand_reference;
	int credit;
	int stock;
};
typedef struct article article;

struct article_list {
	struct article article[5];
	int nb_different_article;
};
typedef struct article_list article_list;

enum connu_panoply {
	Par_une_amie = 1,
	Une_recherche_en_ligne = 2,
	Un_article_de_presse = 3,
	Aux_galerie_lafayette = 4,
	Sur_les_reseaux_sociaux = 5,
	Autre = 6,
};
typedef enum connu_panoply connu_panoply;

struct mail {
	char email[25];
};
typedef struct mail mail;

struct mot_de_passe {
	char mdp[25];
};
typedef struct mot_de_passe mot_de_passe;

struct date {
	int jour;
	int mois;
	int annee;
};
typedef struct date date;

struct identifiants {
	struct mail email;
	struct mot_de_passe mdp;
};
typedef struct identifiants identifiants;

struct compte {
	int id_compte;
	struct mail email;
	struct mot_de_passe mdp;
	char nom[25];
	char prenom[25];
	struct date date_de_naissance;
	int telephone;
	char profession[25];
	char pays[25];
	int nb_credit;
	enum connu_panoply connaissance;
	struct abonnement abonnement_suivi;
	struct date date_abonnement;
};
typedef struct compte compte;

struct list_account {
	struct compte cmpt[5];
	int nbCompte;
};
typedef struct list_account list_account;

struct cart {
	int id_cart;
	struct article list_article[5];
	int nbArticle;
	int rent_price_credit;
	int rent_price_euros;
	enum point_livraison pt_livraison;
	struct date date_livraison;
	struct date date_rendu;
};
typedef struct cart cart;

struct historiqueCommande {
	struct cart listCommande[5];
	int nbCommande;
};
typedef struct historiqueCommande historiqueCommande;

struct panoply {
	struct list_account comptes;
	struct list_collection collections;
	struct article_list articles;
	struct list_abonnement abonnements;
	struct list_brand marques;
	struct historiqueCommande commandes;
};
typedef struct panoply panoply;

#define SERVICE_PANOPLY 0x20646464
#define SERVICE_VERSION_2 1

#if defined(__STDC__) || defined(__cplusplus)
#define INIT 1
extern  void * init_1(void *, CLIENT *);
extern  void * init_1_svc(void *, struct svc_req *);
#define CREATE_ACCOUNT 2
extern  compte * create_account_1(compte *, CLIENT *);
extern  compte * create_account_1_svc(compte *, struct svc_req *);
#define LOG_IN 3
extern  int * log_in_1(identifiants *, CLIENT *);
extern  int * log_in_1_svc(identifiants *, struct svc_req *);
#define LIST_ALL_COLLECTION 4
extern  list_collection * list_all_collection_1(void *, CLIENT *);
extern  list_collection * list_all_collection_1_svc(void *, struct svc_req *);
#define ADD_CLOTH_TO_COLLECTION 5
extern  void * add_cloth_to_collection_1(article *, CLIENT *);
extern  void * add_cloth_to_collection_1_svc(article *, struct svc_req *);
#define REMOVE_CLOTH_TO_COLLECTION 6
extern  void * remove_cloth_to_collection_1(article *, CLIENT *);
extern  void * remove_cloth_to_collection_1_svc(article *, struct svc_req *);
#define DISPLAY_ABONNEMENT 7
extern  list_account * display_abonnement_1(void *, CLIENT *);
extern  list_account * display_abonnement_1_svc(void *, struct svc_req *);
extern int service_panoply_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define INIT 1
extern  void * init_1();
extern  void * init_1_svc();
#define CREATE_ACCOUNT 2
extern  compte * create_account_1();
extern  compte * create_account_1_svc();
#define LOG_IN 3
extern  int * log_in_1();
extern  int * log_in_1_svc();
#define LIST_ALL_COLLECTION 4
extern  list_collection * list_all_collection_1();
extern  list_collection * list_all_collection_1_svc();
#define ADD_CLOTH_TO_COLLECTION 5
extern  void * add_cloth_to_collection_1();
extern  void * add_cloth_to_collection_1_svc();
#define REMOVE_CLOTH_TO_COLLECTION 6
extern  void * remove_cloth_to_collection_1();
extern  void * remove_cloth_to_collection_1_svc();
#define DISPLAY_ABONNEMENT 7
extern  list_account * display_abonnement_1();
extern  list_account * display_abonnement_1_svc();
extern int service_panoply_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_abonnement (XDR *, abonnement*);
extern  bool_t xdr_list_abonnement (XDR *, list_abonnement*);
extern  bool_t xdr_collection (XDR *, collection*);
extern  bool_t xdr_list_collection (XDR *, list_collection*);
extern  bool_t xdr_brand (XDR *, brand*);
extern  bool_t xdr_list_brand (XDR *, list_brand*);
extern  bool_t xdr_point_livraison (XDR *, point_livraison*);
extern  bool_t xdr_article (XDR *, article*);
extern  bool_t xdr_article_list (XDR *, article_list*);
extern  bool_t xdr_connu_panoply (XDR *, connu_panoply*);
extern  bool_t xdr_mail (XDR *, mail*);
extern  bool_t xdr_mot_de_passe (XDR *, mot_de_passe*);
extern  bool_t xdr_date (XDR *, date*);
extern  bool_t xdr_identifiants (XDR *, identifiants*);
extern  bool_t xdr_compte (XDR *, compte*);
extern  bool_t xdr_list_account (XDR *, list_account*);
extern  bool_t xdr_cart (XDR *, cart*);
extern  bool_t xdr_historiqueCommande (XDR *, historiqueCommande*);
extern  bool_t xdr_panoply (XDR *, panoply*);

#else /* K&R C */
extern bool_t xdr_abonnement ();
extern bool_t xdr_list_abonnement ();
extern bool_t xdr_collection ();
extern bool_t xdr_list_collection ();
extern bool_t xdr_brand ();
extern bool_t xdr_list_brand ();
extern bool_t xdr_point_livraison ();
extern bool_t xdr_article ();
extern bool_t xdr_article_list ();
extern bool_t xdr_connu_panoply ();
extern bool_t xdr_mail ();
extern bool_t xdr_mot_de_passe ();
extern bool_t xdr_date ();
extern bool_t xdr_identifiants ();
extern bool_t xdr_compte ();
extern bool_t xdr_list_account ();
extern bool_t xdr_cart ();
extern bool_t xdr_historiqueCommande ();
extern bool_t xdr_panoply ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_PANOPLY_H_RPCGEN */
