# codeBlast.sql was originally generated by the autoSql program, which also 
# generated codeBlast.c and codeBlast.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#Table storing the codes and positional info for blast runs.
CREATE TABLE codeBlast (
    bin smallint not null,	# bin for browser speed up
    chrom varchar(255) not null,	# Chromosome or FPC contig
    chromStart int unsigned not null,	# Start position in chromosome
    chromEnd int unsigned not null,	# End position in chromosome
    name varchar(255) not null,	# Name of item
    score int unsigned not null,	# Score (0-1000)
    strand char(1) not null,	# Strand
    code varchar(255) not null,	# BLAST code scores
              #Indices
    PRIMARY KEY(bin)
);
