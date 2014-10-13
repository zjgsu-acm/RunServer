RunServer: main.go ./Cjudger/runner.cc ./Cjudger/compiler.cc
	go build
	g++ ./Cjudger/runner.cc -o runner
	g++ ./Cjudger/compiler.cc -o compiler
	bash < ./make.sh
	echo Success
