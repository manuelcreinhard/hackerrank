use Data::Dumper;
my $cmd = shift;

my @cmds = split("\n", `ls -1 commands | sed -e 's/\..*\$//'`);

if($cmd !~ @cmds){
	print '{"error":"command not available"}';
	exit 0;
}
