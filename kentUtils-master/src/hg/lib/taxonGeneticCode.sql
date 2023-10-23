# taxonGeneticCode.sql was originally generated by the autoSql program, which also 
# generated taxonGeneticCode.c and taxonGeneticCode.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#nbci genetic code table
CREATE TABLE taxonGeneticCode (
    id int unsigned not null,	# genetic code id in GenBank taxonomy database
    abbr varchar(255) not null,	# division code 3 characters 
    name varchar(255) not null,	# division name e.g. BCT, PLN, VRT, MAM, PRI...
    tranlsation varchar(255) not null,	# translation table for this genetic code (one AA per codon 1-64)
    starts varchar(255) not null,	# start codons for this genetic code (one AA per codon 1-64)
    comments varchar(255) not null,	# free-text comments 
              #Indices
    PRIMARY KEY(id)
);
