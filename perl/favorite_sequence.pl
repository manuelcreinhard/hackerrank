use Data::Dumper;
no warnings;
=pod
my $num = <>;
my @arr = ();
for(my $i = 0; $i < $num; $i++){
	<>;
	my $_line = <>;
	my @line = split(" ",$_line);
	$arr[$i] = \@line;
}
=cut
my $graph_ = graph->new();
$graph_->addConn(1,2);
$graph_->addConn(2,3);
$graph_->addConn(3,4);
$graph_->addConn(4,5);
$graph_->printAll();

#print Dumper $graph_;



package graph;
sub new {
	my $class = shift;
	my $self = {
					nmap => {}
		
	};
	bless $self, $class;
	return $self;
}

sub addConn {
	my $self = shift;
	my $a = shift;
	my $b = shift;
	if(!$self->{nmap}->{$a}){
		$self->{nmap}{$a} = graph_node->new($a);
	}
	if(!$self->{nmap}{$b}){
		$self->{nmap}{$b} = graph_node->new($b);
	}
	$self->{nmap}{$a}->addDir($self->{nmap}{$b});
}

sub printAll {
	my $self = shift;
	foreach my $key (keys %{$self->{nmap}}){
		$self->{nmap}{$key}->print();
		print "\n";
	}
}

package graph_node;

sub new {
	my $class = shift;
	my $v = shift;
	my $self = {
		val => $v,
		con => []
	};
	bless $self, $class;
	return $self;
}

sub addDir {
	my $self = shift;
	my $node = shift;
	push @{$self->{con}}, $node;
	
}

sub print {
	my $self = shift;
	print $self->{val};
	print " ";
	foreach my $node (@{$self->{con}}){
		$node->print();
	}
}
