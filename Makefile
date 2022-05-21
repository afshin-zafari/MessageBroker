name=king_test

options = -g -Wall -Wextra -pedantic -std=c++20

ifeq ($(OS),Windows_NT)
	fs=\
	refresh_output=IF EXIST bin\ ( rmdir /s/q bin && mkdir bin) ELSE (mkdir bin)
else
	fs=/
	refresh_output=rm -rf bin && mkdir bin
endif

include_path=-IMessageStore${fs}

sources+= MessageStore${fs}main.cpp
sources+= MessageStore${fs}MessageStore.cpp
sources+= MessageStore${fs}Users.cpp
sources+= MessageStore${fs}Application.cpp
sources+= MessageStore${fs}InfoInput.cpp
sources+= MessageStore${fs}InfoOutput.cpp
sources+= MessageStore${fs}UserMessages.cpp

default: $(name)

$(name): $(sources)
	$(refresh_output)
	g++-10 $(options) $(include_path) -o bin${fs}$@ $^
