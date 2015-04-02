use strict;
$|++;
my @random_set;
my %seen;
my $file = "rnum.txt";
my $num = 10;

for(my $i = 0; $i < 8; $i++){
	print "Loop $i\n";
	open FH, ">", $file or die $!;
	print FH "$num\n";
	for (1..$num) {
		my $candidate = int rand($num);
		#redo if $seen{$candidate}++;
		print FH "$candidate\n";
		push @random_set, $candidate;
	}
	close FH;
	system("date");
	system("./../cpp/radix_sort < $file > output_radix_sort_$i.txt");
	system("date");
	system("mv $file $file.$i");
	$num *= 10;
}
