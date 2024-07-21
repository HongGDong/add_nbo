TARGET = add-nbo
SOURCE = add-nbo.cpp

$(TARGET): $(SOURCE)
		gcc -o $(TARGET) $(SOURCE)

clean:
		rm -f $(TARGET)
		rm -f *.o

