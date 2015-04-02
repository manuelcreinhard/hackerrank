use jsonbuilder;
use colsToArr;
use Data::Dumper;


my $data = `top -b -n 1`;

#print Dumper $data;

my $sample = "  PID USER      PR  NI    VIRT    RES    SHR S  %CPU %MEM     TIME+ COMMAND
 2263 manuel    20   0  656484  25228  14964 S   6.3  0.3   0:02.93 gnome-term+
 6206 manuel    20   0 1159216 326952  26008 S   6.3  4.0   2:39.13 chrome
 9781 manuel    20   0   29148   1520   1068 R   6.3  0.0   0:00.01 top
    1 root      20   0   33916   3176   1468 S   0.0  0.0   0:01.38 init
    2 root      20   0       0      0      0 S   0.0  0.0   0:00.00 kthreadd
    3 root      20   0       0      0      0 S   0.0  0.0   0:00.03 ksoftirqd/0
    5 root       0 -20       0      0      0 S   0.0  0.0   0:00.00 kworker/0:+
    7 root      20   0       0      0      0 S   0.0  0.0   0:02.70 rcu_sched
    8 root      20   0       0      0      0 S   0.0  0.0   0:01.34 rcuos/0
    9 root      20   0       0      0      0 S   0.0  0.0   0:01.08 rcuos/1
   10 root      20   0       0      0      0 S   0.0  0.0   0:01.25 rcuos/2
   11 root      20   0       0      0      0 S   0.0  0.0   0:01.12 rcuos/3
   12 root      20   0       0      0      0 S   0.0  0.0   0:00.00 rcuos/4
   13 root      20   0       0      0      0 S   0.0  0.0   0:00.00 rcuos/5
   14 root      20   0       0      0      0 S   0.0  0.0   0:00.00 rcuos/6
   15 root      20   0       0      0      0 S   0.0  0.0   0:00.00 rcuos/7
   16 root      20   0       0      0      0 S   0.0  0.0   0:00.00 rcu_bh
   17 root      20   0       0      0      0 S   0.0  0.0   0:00.00 rcuob/0
   18 root      20   0       0      0      0 S   0.0  0.0   0:00.00 rcuob/1
   19 root      20   0       0      0      0 S   0.0  0.0   0:00.00 rcuob/2
   20 root      20   0       0      0      0 S   0.0  0.0   0:00.00 rcuob/3
   21 root      20   0       0      0      0 S   0.0  0.0   0:00.00 rcuob/4
   22 root      20   0       0      0      0 S   0.0  0.0   0:00.00 rcuob/5
   23 root      20   0       0      0      0 S   0.0  0.0   0:00.00 rcuob/6
";
#print $sample;


my $converter = colsToArr->new();
$converter->setData($sample);
my $header = $converter->getHeader();
my $dataJson = $converter->getArray();

my $js = jsonbuilder->new();
$js->setHeaders($header);
$js->setData($dataJson);
$js->toJson();

=pod
my @arr = split("\n",$sample);
my @finalArr = ();
print "Printing arr\n";
print Dumper @arr;

for my $line (@arr){
	print "Printing line\n";
	$line =~ s/^\s+//;
	my @temp = split(/\s+/,$line);
	
	#print Dumper @temp;
	push @finalArr, \@temp;
}

print Dumper @finalArr;
=cut
