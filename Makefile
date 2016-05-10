#
# Notice the difference between good and bad
#
#

all:
	g++ -o sample sample.c -lgtest -lgmock -lpthread

correct:
	g++ -o sample sample.c  -lgmock -lgtest -lpthread


incorrect:
	g++ -o sample sample.c -lgtest -lgmock -lpthread
