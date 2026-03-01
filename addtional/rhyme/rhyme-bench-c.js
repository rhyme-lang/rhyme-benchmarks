const { rh, api } = require("../../rhyme/src/rhyme")
const { compile } = require("../../rhyme/src/simple-eval")
const { typing, types } = require("../../rhyme/src/typing")
const { runtime: rt } = require("../../rhyme/src/simple-runtime")

let outDir = "out"

let settings = {
  backend: "c-new",
  schema: types.never,
  outDir,
  enableOptimizations: false,
  hashSize: 65536,
  nestedHashSize: 2048
}

let schema = typing.parseType(`{
  *u32: {
    *u32: {
      sha: string,
      commit: {
        author: {
          name: string,
          date: string
        },
        committer: {
          name: string,
          date: string
        }
      },
      parents: {
        *u32: unknown
      }
    }
  }
}`)
let commits = rh`loadNDJSON "../data/commits.json" ${schema}`

async function q1() {
  let t1 = performance.now()

  // author name -> year -> month -> commits
  let query = rh`sort {
    ${commits}.*i.*j.commit.author.name: {
      email: first ${commits}.*i.*j.commit.author.email,
      total_commits: count ${commits}.*i.*j,
      yearly_activity: {
        (substr ${commits}.*i.*j.commit.author.date 0 4): {
          total_commits: count ${commits}.*i.*j,
          monthly_activity: {
            (substr ${commits}.*i.*j.commit.author.date 0 7): {
              total_commits: count ${commits}.*i.*j
            }
          }
        }
      }
    }
  } "total_commits" 1`

  let f = await compile(query, {
    ...settings, outFile: "q1",
    hashSize: 65536,
    nestedHashSize: 64,
    limit: 5
  })
  let t3 = performance.now()
  let t2 = f.explain.time
  //console.log("Q1 Rhyme compilation: " + (t2 - t1) + " ms")
  //console.log("Q1 C compilation: " + (t3 - t2) + " ms")
  console.log("Compilation: " + (t3 - t1) + " ms")
}

async function q2() {
  let t1 = performance.now()

  // author name -> committer name -> commits
  let query = rh`sort {
    ${commits}.*i.*j.commit.author.name: {
      email: first ${commits}.*i.*j.commit.author.email,
      total_commits: count ${commits}.*i.*j,
      self_committed: count (${commits}.*i.*j.commit.committer.name == ${commits}.*i.*j.commit.author.name) & ${commits}.*i.*j,
      committed_by_others: {
        (${commits}.*i.*j.commit.committer.name != ${commits}.*i.*j.commit.author.name) & ${commits}.*i.*j.commit.committer.name: {
          email: first ${commits}.*i.*j.commit.committer.email,
          commits: count ${commits}.*i.*j
        }
      }
    }
  } "total_commits" 1`

  let f = await compile(query, {
    ...settings, outFile: "q2",
    hashSize: 65536,
    nestedHashSize: 1024,
    limit: 5
  })
  let t3 = performance.now()
  let t2 = f.explain.time
  //console.log("Rhyme compilation: " + (t2 - t1) + " ms")
  //console.log("C compilation: " + (t3 - t2) + " ms")
}

async function q3() {
  let t1 = performance.now()

  // Commit hour of day -> number of unique authors
  let phase1 = rh`{
    (substr ${commits}.*i.*j.commit.author.date 11 13): {
      hour: single (substr ${commits}.*i.*j.commit.author.date 11 13),
      total_commits: count ${commits}.*i.*j,
      unique_authors: {
        ${commits}.*i.*j.commit.author.name: count ${commits}.*i.*j
      }
    }
  }`

  let query = rh`sort {
    ${phase1}.*count.hour: {
      total_commits: single ${phase1}.*count.total_commits,
      unique_authors: length ${phase1}.*count.unique_authors
    }
  } "unique_authors" 1`

  let f = await compile(query, {
    ...settings, outFile: "q3",
    hashSize: 64,
    nestedHashSize: 8192
  })
  let t3 = performance.now()
  let t2 = f.explain.time
  //console.log("Rhyme compilation: " + (t2 - t1) + " ms")
  //console.log("C compilation: " + (t3 - t2) + " ms")
}

async function q4() {
  let t1 = performance.now()

  let query = rh`sort {
    ${commits}.*i.*j.commit.author.name: {
      email: first ${commits}.*i.*j.commit.author.email,
      total_commits: count ${commits}.*i.*j,
      merge_commits: count (length ${commits}.*i.*j.parents) > 1 & ${commits}.*i.*j
    }
  } "merge_commits" 1`

  let f = await compile(query, {
    ...settings, outFile: "q4",
    hashSize: 65536,
    limit: 20
  })
  let t3 = performance.now()
  let t2 = f.explain.time
  //console.log("Rhyme compilation: " + (t2 - t1) + " ms")
  //console.log("C compilation: " + (t3 - t2) + " ms")
}

let args = process.argv

let q = Number(args[2])

if (args[3]) settings.compiler = args[3]
if (args[4]) settings.cFlags = args[4]

//console.log(args)

switch (q) {
  case 1:
    q1()
    break
  case 2:
    q2()
    break
  case 3:
    q3()
    break
  case 4:
    q4()
    break
  default:
    q1()
    q2()
    q3()
    q4()
}
