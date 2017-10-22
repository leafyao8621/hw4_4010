library(ks)
a = read.csv("pdata.csv")[,1]
hist(a, main = "Max Number Removed", xlab = "value", ylab = "frequency")
fhat = kde(a, positive = TRUE)
plot(fhat, main = "Kernel Density Estimate")
hist(a, prob = TRUE, add = TRUE)
