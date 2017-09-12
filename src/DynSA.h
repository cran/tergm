/*  File src/DynSA.h in package tergm, part of the Statnet suite
 *  of packages for network analysis, http://statnet.org .
 *
 *  This software is distributed under the GPL-3 license.  It is free,
 *  open source, and has the attribution requirements (GPL Section 7) at
 *  http://statnet.org/attribution
 *
 *  Copyright 2008-2017 Statnet Commons
 */
#ifndef DYNSA_H
#define DYNSA_H

#include "MCMCDyn.h"
#include "MHproposal.h"

void MCMCDynSArun_wrapper(// Observed network.
			     int *tails, int *heads, int *time, int *lasttoggle, int *n_edges,
			     int *n_nodes, int *dflag, int *bipartite, 
			     // Formation terms and proposals.
			     int *F_nterms, char **F_funnames, char **F_sonames,
			     char **F_MHproposaltype, char **F_MHproposalpackage,
			     double *F_inputs,
			     // Dissolution terms and proposals.
			     int *D_nterms, char **D_funnames, char **D_sonames, 
			     char **D_MHproposaltype, char **D_MHproposalpackage,
			     double *D_inputs,
			     // Parameter fitting.
			     double *eta0,
			     int *M_nterms, char **M_funnames, char **M_sonames, double *M_inputs,
			     double *init_dev,
			     int *runlength,
			     double *WinvGradient,
			     double *jitter, double *dejitter,
			     double *dev_guard,
			     double *par_guard,
			     // Degree bounds.
			     int *attribs, int *maxout, int *maxin, int *minout,
			     int *minin, int *condAllDegExact, int *attriblength,
			     // MCMC settings.
			     int *SA_burnin, int *SA_interval, int *min_MH_interval, int *max_MH_interval, double *MH_pval, double *MH_interval_add,
			     // Space for output.
			     int *maxedges, int *maxchanges,
			     int *newnetworktail, int *newnetworkhead, 
			     double *opt_history,
			     // Verbosity.
			     int *fVerbose,
			     int *status);
MCMCDynStatus MCMCDynSArun(// Observed and discordant network.
			      Network *nwp,
			      // Formation terms and proposals.
			      Model *F_m, MHproposal *F_MH,
			      // Dissolution terms and proposals.
			      Model *D_m, MHproposal *D_MH,
			      // Model fitting.
			      double *eta, 
			      Model *M_m,
			      double *dev, // DEViation of the current network's targeted statistics from the target statistics.
			      int runlength,
			      double *WinvGradient, double *jitter, double *dejitter, 
			      double *dev_guard, double *par_guard,
			      
			      // Space for output.
			      Edge maxedges, Edge maxchanges,
			      Vertex *difftime, Vertex *difftail, Vertex *diffhead,
			      double *opt_history,
			      // MCMC settings.
			      unsigned int SA_burnin, unsigned int SA_interval, unsigned int min_MH_interval, unsigned int max_MH_interval, double MH_pval, double MH_interval_add,
			      // Verbosity.
			      int fVerbose);
#endif
