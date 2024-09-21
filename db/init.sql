CREATE TABLE Items (
    ID SERIAL PRIMARY KEY,
    Name VARCHAR(255),
    Image_Url TEXT,
    Description TEXT
);

CREATE TABLE Lists (
    ID SERIAL PRIMARY KEY,
    Items INTEGER[],
    Name VARCHAR(255),
    Image_Url TEXT,
    Description TEXT
);
