#--create local repo then connect to remote repo\
&emsp; $ git init vc-lab2\
&emsp;$ git remote add origin https://github.com/emanibrahim0m/vc-iti-lab2.git\
\
	touch gitcommand.txt\
#-- create first commit\
&emsp;$ git add .\
&emsp;$ git commit -m "First File"\
&emsp;$ git push -u origin main\
\
#--create dev branch (create commit - push - merge)\
&emsp;$ git branch dev\
&emsp;$ git switch Dev\
	&emsp;&emsp;touch dev.txt\
&emsp;$ git add .\
&emsp;$ git commit -m "Dev Branch"\
&emsp;$ git checkout main\
&emsp;$ git push -u origin dev\
&emsp;$ git merge Dev\
\
#--create test branch (create commit - push - merge)\
&emsp;$ git branch Test\
&emsp;$ git switch Test\
	&emsp;&emsp;touch Test.txt\
&emsp;$ git add .\
&emsp;$ git commit -m "Test Branch"\
&emsp;$ git checkout main\
&emsp;$ git push Test\
&emsp;$ git merge Test\
\
#-- delete branches from remote\
&emsp;git push origin --delete Test\
&emsp;git push origin --delete Dev\
\
#-- delete branches from local\
&emsp;git checkout main\
&emsp;git branch -d Test\
&emsp;git branch -d Dev\
\
#-- save changes in main without commit\
$ git branch New\
&emsp;git stash\
&emsp;git checkout New\
&emsp;git stash pop\
\
#--create annotated tag\
&emsp;$ git tag -a v1.7 -m "Annotated tag"\
\
#-- push tag to remote repo\
&emsp;git push origin v1.7\
\
#--List tags\
&emsp;git tag\
\
#--delete tag locally\
&emsp;git tag -d v1.7\
\
#--delete tag Remotely\
&emsp;git push origin --delete v1.7\
\
\
\
<img width="597" height="335" alt="images" src="https://github.com/user-attachments/assets/aa17f3c9-7af9-4e8d-8b7d-91e02c2382ae" />\
