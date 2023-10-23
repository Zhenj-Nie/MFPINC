/* wgEncodeGencodePolyAFeature.h was originally generated by the autoSql program, which also 
 * generated wgEncodeGencodePolyAFeature.c and wgEncodeGencodePolyAFeature.sql.  This header links the database and
 * the RAM representation of objects. */

/* Copyright (C) 2011 The Regents of the University of California 
 * See README in this or parent directory for licensing information. */

#ifndef WGENCODEGENCODEPOLYAFEATURE_H
#define WGENCODEGENCODEPOLYAFEATURE_H

#define WGENCODEGENCODEPOLYAFEATURE_NUM_COLS 8

enum wgEncodeGencodePolyAFeatureFeature
    {
    wgEncodeGencodePolyAFeaturePolyA_signal = 0,
    wgEncodeGencodePolyAFeaturePolyA_site = 1,
    wgEncodeGencodePolyAFeaturePseudo_polyA = 2,
    };
struct wgEncodeGencodePolyAFeature
/* GENCODE PolyA feature annotation in transcript and genome */
    {
    struct wgEncodeGencodePolyAFeature *next;  /* Next in singly linked list. */
    char *transcriptId;	/* GENCODE transcript identifier */
    int transcriptStart;	/* starting position in transcript: */
    int transcriptEnd;	/* ending position in transcript: */
    char *chrom;	/* chromosome */
    int chromStart;	/* start in chromosome */
    int endStart;	/* end in chromosome */
    char strand;	/* strand */
    enum wgEncodeGencodePolyAFeatureFeature feature;	/* type of annotation */
    };

void wgEncodeGencodePolyAFeatureStaticLoad(char **row, struct wgEncodeGencodePolyAFeature *ret);
/* Load a row from wgEncodeGencodePolyAFeature table into ret.  The contents of ret will
 * be replaced at the next call to this function. */

struct wgEncodeGencodePolyAFeature *wgEncodeGencodePolyAFeatureLoad(char **row);
/* Load a wgEncodeGencodePolyAFeature from row fetched with select * from wgEncodeGencodePolyAFeature
 * from database.  Dispose of this with wgEncodeGencodePolyAFeatureFree(). */

struct wgEncodeGencodePolyAFeature *wgEncodeGencodePolyAFeatureLoadAll(char *fileName);
/* Load all wgEncodeGencodePolyAFeature from whitespace-separated file.
 * Dispose of this with wgEncodeGencodePolyAFeatureFreeList(). */

struct wgEncodeGencodePolyAFeature *wgEncodeGencodePolyAFeatureLoadAllByChar(char *fileName, char chopper);
/* Load all wgEncodeGencodePolyAFeature from chopper separated file.
 * Dispose of this with wgEncodeGencodePolyAFeatureFreeList(). */

#define wgEncodeGencodePolyAFeatureLoadAllByTab(a) wgEncodeGencodePolyAFeatureLoadAllByChar(a, '\t');
/* Load all wgEncodeGencodePolyAFeature from tab separated file.
 * Dispose of this with wgEncodeGencodePolyAFeatureFreeList(). */

struct wgEncodeGencodePolyAFeature *wgEncodeGencodePolyAFeatureCommaIn(char **pS, struct wgEncodeGencodePolyAFeature *ret);
/* Create a wgEncodeGencodePolyAFeature out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new wgEncodeGencodePolyAFeature */

void wgEncodeGencodePolyAFeatureFree(struct wgEncodeGencodePolyAFeature **pEl);
/* Free a single dynamically allocated wgEncodeGencodePolyAFeature such as created
 * with wgEncodeGencodePolyAFeatureLoad(). */

void wgEncodeGencodePolyAFeatureFreeList(struct wgEncodeGencodePolyAFeature **pList);
/* Free a list of dynamically allocated wgEncodeGencodePolyAFeature's */

void wgEncodeGencodePolyAFeatureOutput(struct wgEncodeGencodePolyAFeature *el, FILE *f, char sep, char lastSep);
/* Print out wgEncodeGencodePolyAFeature.  Separate fields with sep. Follow last field with lastSep. */

#define wgEncodeGencodePolyAFeatureTabOut(el,f) wgEncodeGencodePolyAFeatureOutput(el,f,'\t','\n');
/* Print out wgEncodeGencodePolyAFeature as a line in a tab-separated file. */

#define wgEncodeGencodePolyAFeatureCommaOut(el,f) wgEncodeGencodePolyAFeatureOutput(el,f,',',',');
/* Print out wgEncodeGencodePolyAFeature as a comma separated list including final comma. */

/* -------------------------------- End autoSql Generated Code -------------------------------- */

#endif /* WGENCODEGENCODEPOLYAFEATURE_H */

