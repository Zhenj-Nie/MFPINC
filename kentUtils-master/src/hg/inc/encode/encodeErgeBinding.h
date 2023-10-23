/* encodeErgeBinding.h was originally generated by the autoSql program, which also 
 * generated encodeErgeBinding.c and encodeErgeBinding.sql.  This header links the database and
 * the RAM representation of objects. */

/* Copyright (C) 2008 The Regents of the University of California 
 * See README in this or parent directory for licensing information. */

#ifndef ENCODEERGEBINDING_H
#define ENCODEERGEBINDING_H

#define ENCODEERGEBINDING_NUM_COLS 14

struct encodeErgeBinding
/* ENCODE experimental data from dbERGEII */
    {
    struct encodeErgeBinding *next;  /* Next in singly linked list. */
    char *chrom;	/* Human chromosome */
    unsigned chromStart;	/* Start position in chromosome */
    unsigned chromEnd;	/* End position in chromosome */
    char *name;	/* Name of read - up to 255 characters */
    unsigned score;	/* Score from 0-1000.  1000 is best */
    char strand[2];	/* Value should be + or - */
    unsigned thickStart;	/* Start of where display should be thick (start codon) */
    unsigned thickEnd;	/* End of where display should be thick (stop codon) */
    unsigned reserved;	/* Always zero for now */
    unsigned blockCount;	/* Number of separate blocks (regions without gaps) */
    unsigned *blockSizes;	/* Comma separated list of block sizes */
    unsigned *chromStarts;	/* Start position of each block in relative to chromStart */
    char *Id;	/* dbERGEII Id */
    char *color;	/* RGB color values */
    };

struct encodeErgeBinding *encodeErgeBindingLoad(char **row);
/* Load a encodeErgeBinding from row fetched with select * from encodeErgeBinding
 * from database.  Dispose of this with encodeErgeBindingFree(). */

struct encodeErgeBinding *encodeErgeBindingLoadAll(char *fileName);
/* Load all encodeErgeBinding from whitespace-separated file.
 * Dispose of this with encodeErgeBindingFreeList(). */

struct encodeErgeBinding *encodeErgeBindingLoadAllByChar(char *fileName, char chopper);
/* Load all encodeErgeBinding from chopper separated file.
 * Dispose of this with encodeErgeBindingFreeList(). */

#define encodeErgeBindingLoadAllByTab(a) encodeErgeBindingLoadAllByChar(a, '\t');
/* Load all encodeErgeBinding from tab separated file.
 * Dispose of this with encodeErgeBindingFreeList(). */

struct encodeErgeBinding *encodeErgeBindingCommaIn(char **pS, struct encodeErgeBinding *ret);
/* Create a encodeErgeBinding out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new encodeErgeBinding */

void encodeErgeBindingFree(struct encodeErgeBinding **pEl);
/* Free a single dynamically allocated encodeErgeBinding such as created
 * with encodeErgeBindingLoad(). */

void encodeErgeBindingFreeList(struct encodeErgeBinding **pList);
/* Free a list of dynamically allocated encodeErgeBinding's */

void encodeErgeBindingOutput(struct encodeErgeBinding *el, FILE *f, char sep, char lastSep);
/* Print out encodeErgeBinding.  Separate fields with sep. Follow last field with lastSep. */

#define encodeErgeBindingTabOut(el,f) encodeErgeBindingOutput(el,f,'\t','\n');
/* Print out encodeErgeBinding as a line in a tab-separated file. */

#define encodeErgeBindingCommaOut(el,f) encodeErgeBindingOutput(el,f,',',',');
/* Print out encodeErgeBinding as a comma separated list including final comma. */

/* -------------------------------- End autoSql Generated Code -------------------------------- */

#endif /* ENCODEERGEBINDING_H */

