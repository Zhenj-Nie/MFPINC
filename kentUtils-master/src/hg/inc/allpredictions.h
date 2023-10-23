/* allpredictions.h was originally generated by the autoSql program, which also 
 * generated allpredictions.c and allpredictions.sql.  This header links the database and
 * the RAM representation of objects. */

/* Copyright (C) 2009 The Regents of the University of California 
 * See README in this or parent directory for licensing information. */

#ifndef ALLPREDICTIONS_H
#define ALLPREDICTIONS_H

#define ALLPREDICTIONS_NUM_COLS 7

struct allpredictions
/* Conserved Domain Description */
    {
    struct allpredictions *next;  /* Next in singly linked list. */
    char *chrom;	/* chromosome */
    unsigned chromStart;	/* Start position in chromosome */
    unsigned chromEnd;	/* End position in chromosome */
    char *name;	/* prediction name */
    unsigned score;	/* Score from 900-1000.  1000 is best */
    char strand[2];	/* Value should be + or - */
    char *source;	/* Gene Prediction Source */
    };

void allpredictionsStaticLoad(char **row, struct allpredictions *ret);
/* Load a row from allpredictions table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct allpredictions *allpredictionsLoad(char **row);
/* Load a allpredictions from row fetched with select * from allpredictions
 * from database.  Dispose of this with allpredictionsFree(). */

struct allpredictions *allpredictionsLoadAll(char *fileName);
/* Load all allpredictions from whitespace-separated file.
 * Dispose of this with allpredictionsFreeList(). */

struct allpredictions *allpredictionsLoadAllByChar(char *fileName, char chopper);
/* Load all allpredictions from chopper separated file.
 * Dispose of this with allpredictionsFreeList(). */

#define allpredictionsLoadAllByTab(a) allpredictionsLoadAllByChar(a, '\t');
/* Load all allpredictions from tab separated file.
 * Dispose of this with allpredictionsFreeList(). */

struct allpredictions *allpredictionsCommaIn(char **pS, struct allpredictions *ret);
/* Create a allpredictions out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new allpredictions */

void allpredictionsFree(struct allpredictions **pEl);
/* Free a single dynamically allocated allpredictions such as created
 * with allpredictionsLoad(). */

void allpredictionsFreeList(struct allpredictions **pList);
/* Free a list of dynamically allocated allpredictions's */

void allpredictionsOutput(struct allpredictions *el, FILE *f, char sep, char lastSep);
/* Print out allpredictions.  Separate fields with sep. Follow last field with lastSep. */

#define allpredictionsTabOut(el,f) allpredictionsOutput(el,f,'\t','\n');
/* Print out allpredictions as a line in a tab-separated file. */

#define allpredictionsCommaOut(el,f) allpredictionsOutput(el,f,',',',');
/* Print out allpredictions as a comma separated list including final comma. */

/* -------------------------------- End autoSql Generated Code -------------------------------- */

#endif /* ALLPREDICTIONS_H */

