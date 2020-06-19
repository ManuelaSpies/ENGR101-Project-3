**Install Instructions (for Linux):**
1. **Project Libraries:**
 * -First you need to download and install the SFML project libraries at https://www.sfml-dev.org/download/sfml/2.5.1/.
 * -Make sure that you download the correct version (for Linux) https://www.sfml-dev.org/files/SFML-2.5.1-linux-gcc-64-bit.tar.gz  
 * -After you have installed the libraries for the project you then have to unzip the file to the folder of your choice.
2. **Project Installation:**
 * -Download the repository with our code at https://github.com/ManuelaSpies/ENGR101-Project-3
 * -Inside the file there are two folders (server and robot).
 * -Open the file makefile (inside the server folder) using Geany or if you have no C compiler then you can use a text  editor.
 * -In the top line in makefile you must replace the address with the address to the folder where your SFML folder is.
 * -Just double check to see if all the lines starting with g++ have a tab in front of them.
 * -Press the "make" button in the geany menu in server.cpp to make (compile and build) the server (maze).
 * -Press "Execute" or F5 to run the server (maze).
3. **Project Code:**
 * -Open the file makefile (inside the robot folder) using Geany.
 * -In the top line in makefile you must replace the address with the address to the folder where your SFML folder is.
 * -In robot.cpp you must press the "make" button to compile and build the code for the robot.
 * -To run the code press "execute" or F5 and then the robot will start moving and finding it's way through the maze.
 
 **C Compiler:**
 
 To use SFML, a C compiler is required. Your Linux machine is likely to already have gcc and g++ installed - check this with 
 ```g++ --version```.
 If that command fails, run
 ```sudo apt install build-essential```
 to install gcc and g++.
 
# ENGR101-Project-3
ENGR101 Project 3 

## Group information
### Members
<em>Everybody will try to work on the code to their best ability.</em>
* Manuela Spies (ManuelaSpies), project manager (organising team meetings, reporting regularly on progress)
* Michael Levy (crypticane), software architect (writing core code and extending functionality)
* Harrison Blackburn Churcher (harrison-bc), software writing, testing & documentation (debugging software and committing to git, writing test cases and documenting performance against milestones)
* Maurice Nolan (morra-eng), software writing, testing & documentation (debugging software and committing to git, writing test cases and documenting performance against milestones)

<strong>Team name - Team 16: 🤔Hmmm🤔</strong> ???
<br><strong>Communication - </strong> Discord server


# Plan
<table>
  <tr>
    <th>Date</th>
    <th>Objective</th>
    <th>Tasks & Goals</th>
  </tr>
  <tr>
    <td>31/05 Sun</td>
    <td>Plan discussion</td>
    <td>Establish plan, prepare GitHub, prepare, intitial Core code by Michael</td>
  </tr>
  <tr>
    <td>03/06 Wed 5:00</td>
    <td>Core done</td>
    <td>Clarify questions with lecturers
    <br>Core testing + documentation done
    <br>Everyone's computer works</td>
  </tr>
  <tr>
    <td>07/06 Sun 4:00</td>
    <td>Completion progress discussion</td>
    <td>Completion code started; aim to make it work
    </td>
  </tr>
  <tr>
    <td>10/06 Wed 5:00</td>
    <td>Completion due</td>
    <td>Completion works
    <br>GitHub ready for wiki marking #1
    <br></td>
  </tr>
  <tr>
    <td>14/06 Sun 4:00</td>
    <td>Challenge progress discussion</td>
    <td>Discuss problems & co with challenge
    <br>Completion fully tested + documented</td>
  </tr>
  <tr>
    <td>17/06 Wed 5:00</td>
    <td>Challenge done.</td>
    <td>Challenge works.</td>
  </tr>
  <tr>
    <td>19/06 Fri</td>
    <td><span style="font-color: red">CODE DUE</span></td>
    <td>Challenge tested, documented, UPLOADED</td>
  </tr>
  <tr>
    <td>21/06 Sun 4:00</td>
    <td>Report discussion</td>
    <td>[here] Individual + group report discussed</td>
  </tr>
  
  <tr>
    <td>24/06 Wed</td>
  <td><span style="color: red">REPORT DUE</span></td>
    <td>Report & all submitted and done! :D</td>
  </tr>
</table>

# Michael's To Do List
<table>
  <tr>
    <th>Deadline</th>
    <th>To Do</th>
  </tr>
  <tr>
    <td>03/06 Wed 5:00</td>
    <td>- Do core code + put code up on GitHub
    <br>- Comment on code so we can understand
    <br>- start looking into completion</td>
  </tr>
  
  <tr>
    <td>07/06 Wed 4:00</td>
  <td>none</td>
  </tr>

   <tr>
    <td>14/06 Sun 4:00</td>
  <td>Challenge code</td>
  </tr>

   <tr>
    <td>17/06 Sun 5:00</td>
  <td>Challenge code</td>
  </tr>
  <tr>
    <td>Submission date</td>
    <td>Reports</td>
  </tr>
 </table>
 
 # Harrison's To Do List
 
<table>
  <tr>
    <th>Deadline</th>
    <th>To Do</th>
  </tr>
  <tr>
    <td>03/06 Wed 5:00</td>
    <td>- Make GitHub + SFML & co work on your computer
    <br>- Familiarise + understand Michael's Core code
    <br>- maybe: suggest improvements, ... for Core
    <br>- test + document Core code
    <br>- once testing is done, join Michael in completion</td>
  </tr>
  <tr>
    <td>None</td>
    <td>Get well soon! :)</td>
  </tr>
  <tr>
    <td>17/06 Wed 5:00</td>
    <td>Help with Challenge</td>
  </tr>
  <tr>
    <td>Submission date</td>
    <td>Reports</td>
  </tr>
 </table>
 
 # Maurice's To Do List
 
<table>
  <tr>
    <th>Deadline</th>
    <th>To Do</th>
  </tr>
  <tr>
    <td>03/06 Wed 5:00</td>
    <td>- Make GitHub + SFML & co work on your computer
    <br>- Familiarise + understand Michael's Core code
    <br>- maybe: suggest improvements, ... for Core
    <br>- once stuff works: join Harrison in testing & Completion</td>
  </tr>
  
  <tr>
    <td>07/06 Sun 4:00</td>
    <td>- Test program (Core)
    <br>- whatever comes out of the questions with the lecturers</td>
  </tr>
      
  <tr>
    <td>07/06 Wed 4:00</td>
    <td>- Test program (Completion)</td>
  </tr>
  <tr>
    <td>14/06 Sun 4:00</td>
    <td>Individual log & any testing/... that comes up</td>
  </tr>
  <tr>
    <td>17/06 Wed 5:00</td>
    <td>Instructions</td>
  </tr>
  <tr>
    <td>Submission date</td>
    <td>Reports</td>
  </tr>
 </table>
 
 # Ella's To Do List
 
<table>
  <tr>
    <th>Deadline</th>
    <th>To Do</th>
  </tr>
  <tr>
    <td>03/06 Wed 5:00</td>
    <td>- Make GitHub + SFML & co work on your computer
    <br>- Familiarise + understand Michael's Core code
    <br>- maybe: suggest improvements, ... for Core
    <br>- set up plan/outlines (into read.me for now -- probs move to own folder later?)
    <br>- clarify questions with lecturers
    <br>- log call Sun 31/05
    <br>- once stuff runs: testing + completion</td>
  </tr>
  <tr>
    <td>07/06 Sun 4:00</td>
    <td>- Test program (Core)
    <br>- confirm questions with lecturers
      <br>- whatever comes out of the questions with the lecturers</td>
  </tr>
  
  <tr>
    <td>10/06 Wed 5:00</td>
    <td>- Test program (Completion)
    <br>- confirm questions with lecturers
      <br>- write report</td>
  </tr>
  <tr>
    <td>14/06 Sun 4:00</td>
    <td>Individual log & notes for group report
  </tr>
  <tr>
    <td>17/06 Sun 5:00</td>
    <td>Group report notes & move planning
  </tr>
  <tr>
    <td>Submission date</td>
    <td>Reports</td>
  </tr>
 </table>

