from django import forms
from emp.models import Emp


class CreateForm(forms.ModelForm):
    class Meta:
        model = Emp
        fields = '__all__'
