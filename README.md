# UT-messenger
 a simple messenger made with C++ and works with command line
 
 my finall project at Introduction to Computing Systems and Programming course.
 
 in this project I was not allowed to use some library like string.
 
 for signing up user should type :
 
 <pre><code>signup &lt;username&gt; &lt;password&gt; &lt;phonenumber&gt;
</code></pre>

 
 * the phone number must be 12 digits, and start with 0.
 
 * password must be at least 6 char or number
 
 
 for login user should type : 
 
 <pre><code>login &lt;username&gt; &lt;pass&gt;</code></pre>
 
 
 for logout user should type :  <pre><code>logout</code></pre>
 
 if user wants to change his username or password should type : 
 <pre><code>edit_username &lt;new username&gt;
edit_pass &lt;new password&gt;
</code></pre>
 
 for sending message to another user we should type : <pre><code>send &lt;username&gt; &lt;content&gt; </code></pre>
 
 
 if a use wants to see all users, he should type : <pre><code>info</code></pre>
 
 
 if a use wants to a Specefic users, he should type : <pre><code>about &lt;username&gt;   </code></pre>
 
 
 if person wants to see the recieved message from a Specefic users, he should type : <pre><code>show_received &lt;username&gt;</code></pre>
 
 and if he wants to see the sent messages to a Specefic users, he must type :<pre><code>show_sent &lt;username&gt; </code></pre>
 
 and for close user shoud type : <pre><code>close</code></pre>
 
 
 
 
 
 
 
