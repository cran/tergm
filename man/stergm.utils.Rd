% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/stergm.utils.R
\name{.extract.fd.formulae}
\alias{.extract.fd.formulae}
\title{An Internal Function for Extracting (Some) Formation and Dissolution Formulas from a Combined Formula}
\usage{
.extract.fd.formulae(formula)
}
\arguments{
\item{formula}{a \code{formula}.}
}
\value{
A \code{list} containing \code{form}, \code{pers}, \code{nonsep}, and \code{all} formulas as described above.
}
\description{
This function is used in \code{tergm.EGMME.initialfit} and also when targets or monitoring
formulas are specified by characters.  It makes a basic attempt to identify the
formation and dissolution formulas within a larger combined formula (which may also
include non-separable terms).  Instances of \code{Form} at the top level (which may occur
inside \code{offset}) contribute to the formation formula; instances of \code{Persist} and
\code{Diss} at the top level (which may also occur inside \code{offset}) contribute to the
dissolution formula.  All other terms are regarded as non-separable; this includes instances
of \code{Form}, \code{Persist}, and \code{Diss} that occur inside other operator terms,
including inside \code{Offset}, and also includes all interactions at the top level (for which
the top level term is effectively the interaction operator \code{*} or \code{:}),
whether or not they include \code{Form}, \code{Persist}, and/or \code{Diss}.
The formation and dissolution formulas are obtained by adding
the contributing terms, replacing \code{Form} and \code{Persist} with trivial operators that protect
the environments of their formula arguments but have no effect on statistics or coefficient names
(meaning the formulas effectively become cross-sectional), and replacing \code{Diss} by a similar operator
that negates statistics.  These are included in the return value as the \code{form} and \code{pers}
elements of the list (the "dissolution" formula really being the persistence formula), which also includes
the formula of non-separable terms as \code{nonsep}, and the formula of all terms after replacing
\code{Form}, \code{Persist}, and \code{Diss} as described above as \code{all}.

If usage proves problematic, one may specify the monitoring and/or targets formulas explicitly
(rather than by characters), and one may pass initial coefficient values for the EGMME to avoid
running \code{tergm.EGMME.initialfit}.
}
