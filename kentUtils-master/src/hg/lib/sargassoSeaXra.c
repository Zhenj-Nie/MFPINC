/* sargassoSeaXra.c was originally generated by the autoSql program, which also 
 * generated sargassoSeaXra.h and sargassoSeaXra.sql.  This module links the database and
 * the RAM representation of objects. */

/* Copyright (C) 2014 The Regents of the University of California 
 * See README in this or parent directory for licensing information. */

#include "common.h"
#include "linefile.h"
#include "dystring.h"
#include "jksql.h"
#include "sargassoSeaXra.h"


void sargassoSeaXraStaticLoad(char **row, struct sargassoSeaXra *ret)
/* Load a row from sargassoSeaXra table into ret.  The contents of ret will
 * be replaced at the next call to this function. */
{

ret->qName = row[0];
strcpy(ret->code, row[1]);
ret->evalue = row[2];
ret->GI = sqlUnsigned(row[3]);
ret->PI = atof(row[4]);
ret->length = sqlUnsigned(row[5]);
ret->gap = sqlUnsigned(row[6]);
ret->score = sqlUnsigned(row[7]);
ret->queryseqstart = sqlUnsigned(row[8]);
ret->queryseqend = sqlUnsigned(row[9]);
strcpy(ret->species, row[10]);
ret->thisseqstart = sqlUnsigned(row[11]);
ret->thisseqend = sqlUnsigned(row[12]);
}

struct sargassoSeaXra *sargassoSeaXraLoad(char **row)
/* Load a sargassoSeaXra from row fetched with select * from sargassoSeaXra
 * from database.  Dispose of this with sargassoSeaXraFree(). */
{
struct sargassoSeaXra *ret;

AllocVar(ret);
ret->qName = cloneString(row[0]);
strcpy(ret->code, row[1]);
ret->evalue = cloneString(row[2]);
ret->GI = sqlUnsigned(row[3]);
ret->PI = atof(row[4]);
ret->length = sqlUnsigned(row[5]);
ret->gap = sqlUnsigned(row[6]);
ret->score = sqlUnsigned(row[7]);
ret->queryseqstart = sqlUnsigned(row[8]);
ret->queryseqend = sqlUnsigned(row[9]);
strcpy(ret->species, row[10]);
ret->thisseqstart = sqlUnsigned(row[11]);
ret->thisseqend = sqlUnsigned(row[12]);
return ret;
}

struct sargassoSeaXra *sargassoSeaXraLoadAll(char *fileName) 
/* Load all sargassoSeaXra from a whitespace-separated file.
 * Dispose of this with sargassoSeaXraFreeList(). */
{
struct sargassoSeaXra *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[13];

while (lineFileRow(lf, row))
    {
    el = sargassoSeaXraLoad(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct sargassoSeaXra *sargassoSeaXraLoadAllByChar(char *fileName, char chopper) 
/* Load all sargassoSeaXra from a chopper separated file.
 * Dispose of this with sargassoSeaXraFreeList(). */
{
struct sargassoSeaXra *list = NULL, *el;
struct lineFile *lf = lineFileOpen(fileName, TRUE);
char *row[13];

while (lineFileNextCharRow(lf, chopper, row, ArraySize(row)))
    {
    el = sargassoSeaXraLoad(row);
    slAddHead(&list, el);
    }
lineFileClose(&lf);
slReverse(&list);
return list;
}

struct sargassoSeaXra *sargassoSeaXraCommaIn(char **pS, struct sargassoSeaXra *ret)
/* Create a sargassoSeaXra out of a comma separated string. 
 * This will fill in ret if non-null, otherwise will
 * return a new sargassoSeaXra */
{
char *s = *pS;

if (ret == NULL)
    AllocVar(ret);
ret->qName = sqlStringComma(&s);
sqlFixedStringComma(&s, ret->code, sizeof(ret->code));
ret->evalue = sqlStringComma(&s);
ret->GI = sqlUnsignedComma(&s);
ret->PI = sqlFloatComma(&s);
ret->length = sqlUnsignedComma(&s);
ret->gap = sqlUnsignedComma(&s);
ret->score = sqlUnsignedComma(&s);
ret->queryseqstart = sqlUnsignedComma(&s);
ret->queryseqend = sqlUnsignedComma(&s);
sqlFixedStringComma(&s, ret->species, sizeof(ret->species));
ret->thisseqstart = sqlUnsignedComma(&s);
ret->thisseqend = sqlUnsignedComma(&s);
*pS = s;
return ret;
}

void sargassoSeaXraFree(struct sargassoSeaXra **pEl)
/* Free a single dynamically allocated sargassoSeaXra such as created
 * with sargassoSeaXraLoad(). */
{
struct sargassoSeaXra *el;

if ((el = *pEl) == NULL) return;
freeMem(el->qName);
freeMem(el->evalue);
freez(pEl);
}

void sargassoSeaXraFreeList(struct sargassoSeaXra **pList)
/* Free a list of dynamically allocated sargassoSeaXra's */
{
struct sargassoSeaXra *el, *next;

for (el = *pList; el != NULL; el = next)
    {
    next = el->next;
    sargassoSeaXraFree(&el);
    }
*pList = NULL;
}

void sargassoSeaXraOutput(struct sargassoSeaXra *el, FILE *f, char sep, char lastSep) 
/* Print out sargassoSeaXra.  Separate fields with sep. Follow last field with lastSep. */
{
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->qName);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->code);
if (sep == ',') fputc('"',f);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->evalue);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%u", el->GI);
fputc(sep,f);
fprintf(f, "%g", el->PI);
fputc(sep,f);
fprintf(f, "%u", el->length);
fputc(sep,f);
fprintf(f, "%u", el->gap);
fputc(sep,f);
fprintf(f, "%u", el->score);
fputc(sep,f);
fprintf(f, "%u", el->queryseqstart);
fputc(sep,f);
fprintf(f, "%u", el->queryseqend);
fputc(sep,f);
if (sep == ',') fputc('"',f);
fprintf(f, "%s", el->species);
if (sep == ',') fputc('"',f);
fputc(sep,f);
fprintf(f, "%u", el->thisseqstart);
fputc(sep,f);
fprintf(f, "%u", el->thisseqend);
fputc(lastSep,f);
}

/* -------------------------------- End autoSql Generated Code -------------------------------- */

