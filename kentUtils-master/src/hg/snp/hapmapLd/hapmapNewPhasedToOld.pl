#!/usr/bin/perl
# DO NOT EDIT this file in any installed-bin location --
# edit kent/src/hg/snp/hapmapLd/hapmapNewPhasedToOld.pl instead.

# The latest phased haplotypes from HapMap
# (ftp://ftp.ncbi.nlm.nih.gov/hapmap/phasing/2009-02_phaseIII/HapMap3_r2/YRI/TRIOS/)
# use a new format that Haploview doesn't seem to recognize.
# Translate the new format back into the old format
# (e.g. ftp://ftp.ncbi.nlm.nih.gov/hapmap/phasing/2007-08_rel22/phased/)
# for Haploview.

use warnings;
use strict;

if (! $ARGV[0]) {
  die "usage: $0 newHapmap.phased[.gz]\n";
}

my $infile= $ARGV[0];
my $outBase = $infile;
$outBase =~ s/\.gz$//;
my $outPhased = $outBase."_old.phase.gz";
my $outLegend = $outBase."_old_legend.txt.gz";
my $outSample = $outBase."_old_sample.txt.gz";

open(INP, ($infile =~ /\.gz$/) ? "zcat $infile |" : $infile) || die "Can't open $infile: $!\n";
open(OUTP, "| gzip -c > $outPhased") || die "Can't open > $outPhased: $!\n";
open(OUTL, "| gzip -c > $outLegend") || die "Can't open > $outLegend: $!\n";
open(OUTS, "| gzip -c > $outSample") || die "Can't open > $outSample: $!\n";

# The new format begins with a header line.  We extract the sample IDs,
# stripping the _A and _B suffixes (for first and second haplotype of each sample),
# and write out the old format's _sample file.
my $firstLine = <INP>;
$firstLine =~ s/^rsID\t(\w+_)?position(_\w+)?\t// || die;
$firstLine =~ s/_A / /g;
$firstLine =~ s/_B\t/ /g;
my @gtIds = split(" ", $firstLine);
my $gtCount = @gtIds;
die "Where are the genotypes?" if ($gtCount < 2);
die "Odd # genotypes?!" if (($gtCount & 0x1) == 0x1);
for (my $i = 0;  $i < $gtCount;  $i += 2) {
  print OUTS "$gtIds[$i]\n";
  die if ($gtIds[$i] ne $gtIds[$i+1]);
}
close(OUTS);

# The remaining lines in the new format have columns rsID, position
# and one [ACGT] per gtID (two per sample).  rsIDs, positions and the
# bases that will be coded as 0 and 1 are written into the _legend
# file as we go.  The coded genotype values are stored so that we can
# dump them out sideways at the end (rows=samples not rows=SNPs).
print OUTL "rs\tposition\t0\t1\n";
my @sampleHapGts = ();
while (<INP>) {
  my ($rsId, $pos, @gtBases) = split;
  die "Mismatching genotype counts" if (@gtBases != $gtCount);
  my %gtBaseCounts;
  map { $gtBaseCounts{$_}++; } @gtBases;
  my @alleles = reverse sort { $gtBaseCounts{$a} <=> $gtBaseCounts{$b} } keys %gtBaseCounts;
  die "Supposed to have one or two bases" if (@alleles < 1 || @alleles > 2);
  # Omit the non-segregating SNPs:
  next if (@alleles == 1);
  print OUTL "$rsId\t$pos\t$alleles[0]\t$alleles[1]\n";
  my %codes = ( $alleles[0] => 0, $alleles[1] => 1 );
  for (my $i = 0;  $i < $gtCount;  $i++) {
    push @{$sampleHapGts[$i]}, $codes{$gtBases[$i]};
  }
}
close(INP);
close(OUTL);

# Dump 0- and 1-coded genotypes, one row per sample haplotype, one column per rsID:
for (my $i = 0;  $i < $gtCount;  $i++) {
  print OUTP join(" ", @{$sampleHapGts[$i]}) . "\n";
}
close(OUTP);
