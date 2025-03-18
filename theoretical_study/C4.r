data <- read.csv("data.csv")

hist(data,
    main = "Histogramme des proportions de tirages de mains pour j1")

theorique <- c(1/3, 2/3, 2/3, 2/3, 1/3, 2/3, 2/3, 2/3, 1/3)

hist(theorique,
    add = TRUE) 