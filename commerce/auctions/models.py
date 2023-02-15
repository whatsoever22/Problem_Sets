from django.contrib.auth.models import AbstractUser
from django.db import models


class User(AbstractUser):
    pass


class Bids(models.Model):
    time = models.DateTimeField()
    amount = models.IntegerField()
    biddings = models.ManyToManyField(User, blank=True, related_name="biddings")

    def __str__(self):
        return f"{self.amount} at {self.time}"


class Listings(models.Model):
    title = models.CharField(max_length=64)
    description = models.CharField(max_length=500)
    bid = models.ForeignKey(Bids, on_delete=models.CASCADE, related_name="bid")
    image = models.URLField(null=True, blank=True)
    watchlist = models.BooleanField(default=False)
    creator = models.ForeignKey(User, on_delete=models.CASCADE, related_name="creator")
    listings = models.ManyToManyField(User, blank=True, related_name="listings")

    def __str__(self):
        return f"{self.id}: {self.title}"


class Comments(models.Model):
    comments = models.CharField(max_length=500)
    time = models.DateTimeField()

    def __str__(self):
        return f"{self.comments} at {self.time}"