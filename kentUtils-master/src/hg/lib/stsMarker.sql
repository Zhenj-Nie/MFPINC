# stsMarker.sql was originally generated by the autoSql program, which also 
# generated stsMarker.c and stsMarker.h.  This creates the database representation of
# an object which can be loaded and saved from RAM in a fairly 
# automatic way.

#STS marker and its position on golden path and various maps
CREATE TABLE stsMarker (
    chrom varchar(255) not null,	# Chromosome or 'unknown'
    chromStart int not null,	# Start position in chrom - negative 1 if unpositioned
    chromEnd int unsigned not null,	# End position in chrom
    name varchar(255) not null,	# Name of STS marker
    score int unsigned not null,	# Score of a marker = 1000/# of markers it hits
    identNo int unsigned not null,	# Identification number of STS
    ctgAcc varchar(255) not null,	# Contig accession number
    otherAcc varchar(255) not null,	# Accession number of other contigs that the marker hits
    genethonChrom varchar(255) not null,	# Chromosome (no chr) from Genethon map or 0 if none
    genethonPos float not null,	# Position on Genethon map
    marshfieldChrom varchar(255) not null,	# Chromosome (no chr) from Marshfield map or 0 if none
    marshfieldPos float not null,	# Position on Marshfield map
    gm99Gb4Chrom varchar(255) not null,	# Chromosome (no chr) from gm99_bg4 map or 0 if none
    gm99Gb4Pos float not null,	# Position on gm99_bg4 map
    shgcG3Chrom varchar(255) not null,	# Chromosome (no chr) from shgc_g3 map or 0 if none
    shgcG3Pos float not null,	# Position on shgc_g3 map
    wiYacChrom varchar(255) not null,	# Chromosome (no chr) from wi_yac map or 0 if none
    wiYacPos float not null,	# Position on wi_yac map
    shgcTngChrom varchar(255) not null,	# Chromosome (no chr) from shgc_tng map or 0 if none
    shgcTngPos float not null,	# Position on shgc_tng map
    fishChrom varchar(255) not null,	# Chromosome (no chr) from FISH map or 0 if none
    beginBand varchar(255) not null,	# Beginning of range of bands on FISH map
    endBand varchar(255) not null,	# End of range of bands on FISH map
    lab varchar(255) not null,	# Laboratory that placed the FISH clone
              #Indices
    INDEX chrom (chrom(12),chromStart),
    INDEX name (name)
);
